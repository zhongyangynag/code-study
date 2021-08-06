<template>
  <div class="wly-uploader">
    <input @change="fileUpload" :multiple="!isCover" :accept="accept" type="file" class="wly-uploader-input">
    <Button type="primary"><span class="icon-add"></span>本地上传</Button>
  </div>
</template>

<script>
import SparkMD5 from 'spark-md5'
import RocketCos from '@/lib/cos'
import RocketVod from '@/lib/vod'
import { media } from '@/lib/api'
import { merge } from 'lodash'
import { getMIME } from '@/lib/mimetype'
import { mapGetters } from 'vuex'

export default {
  name: 'wly-uploader',
  props: {
    isCover: { // 是否是封面图
      type: Boolean,
      default: false
    },
    fileId: { // 如果是封面图，需要传入对应的fileId
      type: String,
      default: null
    }
  },
  data () {
    let { cos, vod } = window.config
    return {
      cos: new RocketCos(cos),
      vod: new RocketVod(vod),
      accept: '*/*',
      type: 'image',
      uploadCoverToCos: null
    }
  },
  mounted () {
    const type = this.isCover ? 'image' : this.mediaType
    const query = this.$route.query
    if (type === 'attachment') {
      this.accept = '*/*'
      const attachmentType = this.attachmentType
      if (attachmentType) {
        this.accept = attachmentType
      }
    } else {
      const acceptArr = []
      this.subtype.split(',').forEach(s => {
        acceptArr.push(`${type}/${s}`)
      })
      this.accept = acceptArr.join(',')
    }
    this.type = type
    console.log('accept', this.accept, 'query', query)
    this.uploadCoverToCos = query.uploadCoverToCos
  },
  computed: {
    ...mapGetters([
      'categoryId',
      'mediaType',
      'subtype',
      'attachmentType'
    ])
  },
  methods: {
    fileUpload (evt) {
      if (this.isCover) {
        this.$Message.loading({
          content: '封面图上传中…',
          duration: 0
        })
        if (!this.uploadCoverToCos) {
          let uploader = this.vod
          uploader.uploadCover({
            coverFile: evt.target.files[0],
            fileId: this.fileId,
            onSuccess: res => {
              this.$Message.destroy()
              this.$emit('done', res)
            },
            onError: res => {
            }
          })
        } else {
          let uploader = this.cos
          const file = evt.target.files[0]
          const fileName = file.name
          const pos = fileName.lastIndexOf('.')
          const originalFileName = SparkMD5.hash(fileName.substring(0, pos))
          const originalFileExt = fileName.substring(pos, fileName.length)
          const randomString = Math.random().toString(36).substring(3, 8)
          uploader.upload({
            file,
            fileName: `${file.name}${randomString}`,
            // fileId: this.fileId,
            originalFileName,
            originalFileExt,
            type: 'image',
            onSuccess: res => {
              this.$Message.destroy()
              this.$emit('done', res)
            },
            onError: res => {
            }
          })
        }
      } else {
        let { categoryId } = this
        let uploader = this.type === 'image' || this.type === 'attachment' ? this.cos : this.vod
        let params = { media_type: this.type, category_id: categoryId }
        let files = evt.target.files
        // 上传图片大小不能超过10M
        let flag = true
        const accept = this.accept.split(',')
        for (let i = 0; i < files.length; i++) {
          let filetype = files[i].type
          if (!filetype) {
            const arr = files[i].name.split('.')
            const ext = arr[arr.length - 1]
            filetype = getMIME(ext)
            console.log('===filetype===', ext, getMIME(ext))
          }
          const [type, subtype] = filetype.split('/')
          console.log('---filetype---', type, subtype)
          if (this.accept !== '*/*') {
            const match = accept.some(acceptType => {
              console.log('acctpt', acceptType, type, this.type, accept, `${type}/${subtype}`)
              console.log('boolean', acceptType === `${this.type}/*` && type === this.type, accept.indexOf(`${type}/${subtype}`))
              if (acceptType === `${this.type}/*` && type === this.type) return true
              if (accept.indexOf(`${type}/${subtype}`) >= 0) return true
            })
            if (!match) {
              this.$Message.destroy()
              this.$Message.error('不支持该格式')
              return
            }
          }
          if (this.type === 'image' && files[i].size > 10485760) {
            flag = false
            break
          }
        }
        if (flag) {
          let randomString = Math.random().toString(36).substring(3, 8)
          this.$Message.loading({
            content: '素材上传中…',
            duration: 0
          })
          let count = 0
          for (let i = 0; i < files.length; i++) {
            let file = files[i]
            const fileName = file.name
            const pos = fileName.lastIndexOf('.')
            const originalFileName = SparkMD5.hash(fileName.substring(0, pos))
            const originalFileExt = fileName.substring(pos, fileName.length)
            uploader.upload({
              file: file,
              fileName: `${file.name}${randomString}`,
              originalFileName,
              originalFileExt,
              type: this.type,
              onSuccess: ({ data }) => {
                data.name = data.name.slice(0, -5).replace(/[,，]/g, '')
                media.save(merge({}, data, params, { accept: this.accept.split(',') })).then(res => {
                  if (++count === files.length) {
                    // console.log('全部上传完成')
                    document.querySelector('[type="file"]').value = ''
                    this.$Message.destroy()
                    this.$bus.$emit('category.list')
                    this.$bus.$emit('media.list')
                  }
                }).catch(err => {
                  console.log('save catch', err)
                  document.querySelector('[type="file"]').value = ''
                  this.$Message.destroy()
                  this.$Message.error(err.message)
                })
              },
              onError: (err) => {
                console.error(err)
                document.querySelector('[type="file"]').value = ''
                const msg = err && err.code === 25022 ? '不支持该格式' : '上传发生错误'
                this.$Message.destroy()
                this.$Message.error(msg)
              }
            })
          }
        } else {
          document.querySelector('[type="file"]').value = ''
          this.$Message.error('图片大小不能超过10M')
        }
      }
    }
  }
}
</script>

<style lang="less">
  .wly-uploader {
    display: inline-block;
    position: relative;
    overflow: hidden;
    .icon-add:before {
      margin-right: 3px;
      color: #fff;
    }
    &-input {
      position: absolute;
      width: 200px;
      height: 100px;
      top: -25px;
      opacity: 0;
      z-index: 1;
      cursor: pointer;
    }
  }
</style>
