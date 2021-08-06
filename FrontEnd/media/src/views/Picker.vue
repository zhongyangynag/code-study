<template>
  <div class="wly-picker">
    <div class="wly-picker-bar">
      <div class="wly-picker-bar-left">
        <i-select v-model="categoryId" :clearable="true" style="width:200px" placeholder="选择分组">
          <i-option v-for="(category, index) in categoryList" :value="category._id" :key="index">{{ category.category_name }}（{{category.count}}）</i-option>
        </i-select>
        <span class="ml20">已选择{{selectList.length}}<span v-if="mediaType === 'image'">张</span><span v-else>个</span></span>
        <div v-if="setImgWidth" class="input-wrap">
          <span class="ml20 label">图片宽度</span>
          <Input type="number" class="set-width" v-model="imgWidth" placeholder="请输入图片宽度" />
        </div>
        <div v-if="setImg" class="input-wrap">
          <span class="ml20 label">扩展参数</span>
          <Input class="set-width" v-model="imgSetting" placeholder="请输入扩展参数" />
        </div>
      </div>
      <div class="wly-picker-bar-right">
        <wly-uploader></wly-uploader>
      </div>
    </div>
    <div class="wly-picker-body">
      <CheckboxGroup v-if="list.length > 0" v-model="selectList">
        <div class="wly-picker-item" v-for="(item, index) in list" :key="index">
          <div class="wly-picker-item-card">
            <div class="wly-picker-item-warrper">
              <!-- <Checkbox size="large" class="wly-picker-item-chk" :label="item._id" ><span></span></Checkbox> -->
              <!-- <img :src="item.img_url" :alt="item.name"> -->
              <span :class="cardIcon" @click="mediaPlay(item)"></span>
              <wii-image width="100%" height="100%" :src="item.img_url"></wii-image>
            </div>
            <div class="wly-picker-item-bar">
              <Checkbox :label="item._id" class="wly-picker-item-chk"><span></span></Checkbox>
              <span class="wly-picker-item-title">{{item.name}}</span>
            </div>
          </div>
        </div>
      </CheckboxGroup>
      <div v-else class="wly-picker-nodata">
        <span v-if="isLoading">素材列表加载中…</span>
        <span v-else>对不起，在该分组下没有找到任何素材</span>
      </div>
    </div>
    <div class="wly-picker-bottom">
      <Page :current="pagination.current_page" :total="pagination.total" :page-size="pagination.page_size" @on-change="changePage" show-elevator />
      <div class="wly-picker-btn">
        <Button @click="pickerCancel">取消</Button>
        <Button @click="pickerSubmit" type="primary">确定</Button>
      </div>
    </div>
    <Modal
      :title="`${typeName}查看`"
      v-model="playShow"
      @on-cancel="playCancel"
      @on-ok="playCancel"
      :mask-closable="false"
    >
      <video
        id="player-container-id"
        class="modal-video"
        v-if="mediaType === 'video'&&playShow"
        preload="auto" playsinline webkit-playsinline
      ></video>
      <audio
        class="modal-audio"
        controls
        :autoplay="playShow"
        v-else-if="mediaType === 'audio'&&playShow"
        :src="mediaInfo.play_url"
      ></audio>
    </Modal>
  </div>
</template>

<script>
import { media, category } from '@/lib/api'
import { merge } from 'lodash'
import { mapGetters } from 'vuex'
import WiiLoader from 'wiiloader/index.js'
import RocketCookie from '@/lib/cookie'
import commonConfig from '@/configs/common'
const files = [
  '//imgcache.qq.com/open/qcloud/video/tcplayer/tcplayer.css',
  '//imgcache.qq.com/open/qcloud/video/tcplayer/libs/hls.min.0.12.4.js',
  '//imgcache.qq.com/open/qcloud/video/tcplayer/libs/dash.all.min.2.9.3.js',
  '//imgcache.qq.com/open/qcloud/video/tcplayer/tcplayer.min.js'
]
export default {
  name: 'wly-picker',
  data () {
    return {
      playShow: false,
      mediaInfo: {},
      isLoading: true,
      list: [],
      selectList: [],
      limit: null,
      pagination: {
        current_page: 1,
        total: 1,
        page_size: 10
      },
      setImgWidth: false,
      setImg: false,
      imgWidth: 1000,
      imgSetting: '',
      maxCategoryLength: commonConfig.maxCategoryLength
    }
  },
  created () {
    let { type } = this.$route.params
    this.$store.commit('changeMeidaType', type)
    let querys = this.$route.query
    let cookie = new RocketCookie()
    for (let key in querys) {
      if (/^c_\S*/.test(key)) {
        cookie.set(key, querys[key])
      } else if (key === 'source_id') {
        this.$store.commit('changeSource', querys[key])
      } else if (/^p_\S*/.test(key)) {
        let obj = {}
        obj[key] = querys[key]
        this.$store.commit('addExtras', obj)
      }
    }
    this.limit = querys.limit
    this.setImgWidth = !!querys.setimgwidth || !!querys.setImgWidth
    this.setImg = !!querys.setimg || !!querys.setImg
  },
  async mounted () {
    if (this.mediaType === 'video') {
      await WiiLoader.load(files)
    }
    this.getCategoryList()
    this.getList()
    this.$bus.$on('media.list', () => {
      this.getList()
    })
  },
  computed: {
    typeName () {
      let typeList = {
        image: '图片',
        video: '视频',
        audio: '音频',
        attachment: '附件'
      }
      return `${typeList[this.mediaType]}`
    },
    cardIcon () {
      let { mediaType } = this
      let className = `card-icon icon-${mediaType}_play`
      if (mediaType === 'image') {
        className = ''
      }
      return `${className}`
    },
    ...mapGetters([
      'sourceId',
      'categoryList',
      'mediaType'
    ]),
    categoryId: {
      get () {
        return this.$store.state.categoryId
      },
      set (categoryId) {
        this.$store.commit('changeCategory', categoryId)
        this.getList()
        this.pagination.current_page = 1
      }
    }
  },
  watch: {
    selectList (list) {
      const limit = Number(this.limit)
      if (limit && (list.length > limit)) {
        this.$Message.error(`只能选择${this.limit}个素材！`)
        this.$nextTick(() => {
          this.selectList = list.splice(0, limit)
        })
      }
    }
  },
  methods: {
    getCategoryList () {
      if (this.$route.query.maxCategoryLength) {
        this.maxCategoryLength = this.$route.query.maxCategoryLength
      }

      category.list({ source_id: this.sourceId, media_type: this.mediaType, page_size: this.maxCategoryLength }).then(({ list }) => {
        this.$store.commit('fillCategoryList', list)
      })
    },
    getList (params = {}) {
      this.list = []
      this.$nextTick(() => {
        this.isLoading = true
        let data = {
          category_id: this.categoryId,
          media_type: this.mediaType,
          page_size: 9,
          source_id: this.sourceId
        }
        params = merge({}, data, params)
        media.list(params).then(({ list, pagination }) => {
          this.isLoading = false
          this.list = list
          this.pagination = pagination
        })
      })
    },
    changePage (page) {
      this.getList({ p: page })
    },
    pickerCancel () {
      this.selectList = []
      window.parent.postMessage({
        type: 'cancel',
        extras: this.$store.state.extras
      }, '*', [])
    },
    pickerSubmit () {
      // console.log(this.selectList)
      if (this.selectList.length === 0) {
        this.$Message.error('您还没有选择任何素材！')
      } else if (this.limit && this.selectList.length > this.limit) {
        this.$Message.error(`只能选择${this.limit}个素材！`)
      } else {
        let data = {
          _id: this.selectList
        }
        media.detail(data).then(res => {
          // console.log(res)
          let list = []
          if (this.mediaType === 'image') {
            res.forEach(item => {
              let { _id, img_url, name } = item
              let query = ''
              if (this.setImg && this.imgSetting) {
                query = (this.imgSetting[0] === '?' ? '' : '?') + this.imgSetting
              } else if (this.setImgWidth && Number(this.imgWidth) > 0) {
                query = `?imageMogr2/format/jpg|imageView2/2/w/${Number(this.imgWidth)}/q/85`
              }
              const idx = this.selectList.indexOf(_id)
              list[idx] = {
                id: _id,
                url: img_url + query,
                name
              }
            })
          } else {
            res.forEach(item => {
              let { _id, file_id, name, img_url, play_url, attachment_url } = item
              const idx = this.selectList.indexOf(_id)
              list[idx] = {
                id: _id,
                file_id,
                name,
                cover_url: img_url,
                play_url,
                attachment_url
              }
            })
          }
          console.log('list', list)
          // console.log(this.mediaType, list)
          window.parent.postMessage({
            type: this.mediaType,
            list: list,
            extras: this.$store.state.extras
          }, '*', [])
        })
      }
    },
    mediaPlay (item) {
      this.playShow = true
      this.mediaInfo = item
      if (this.mediaType === 'video') {
        this.$nextTick(() => {
          this.player = window.TCPlayer('player-container-id', {
            fileID: this.mediaInfo.file_id,
            appID: window.config.cos.appId,
            autoplay: false,
            poster: this.mediaInfo.img_url
          })
        })
      }
    },
    playCancel () {
      this.playShow = false
      if (this.mediaType === 'video') {
        this.player.dispose()
      }
    }
  }
}
</script>

<style lang="less">
  .ml20 {
    margin-left: 20px;
  }
  .wly-picker {
    height: 100%;
    margin: 0 auto;
    display: flex;
    flex-direction: column;
    &-nodata {
      text-align: center;
      font-size: 14px;
      position: relative;
      top: 50%;
      transform: translateY(-50%);
    }
    &-bar {
      display: flex;
      padding: 15px 10px 10px;
      &-left {
        flex: 1;
        display: flex;
        align-items: center;
      }
    }
    &-body {
      overflow-y: auto;
      flex: 1;
      .ivu-checkbox-group {
        display: flex;
        flex-flow: row wrap;
        align-content: flex-start;
      }
    }
    &-item {
      width: 256px;
      border-radius: 4px;
      overflow: hidden;
      flex: 0 0 33%;
      padding: 10px;
      &-card {
        height: 185px;
        border-radius: 4px;
        border: 1px solid rgba(232, 234, 236, 1);
      }
      &-warrper{
        position: relative;
        height: 144px;
        font-size: 0;
        // box-shadow:0px 1px 2px 0px rgba(0,0,0,0.2);
        border-radius: 4px 4px 0 0;
        background: #f0f0f0;
      }
      img {
        width: 100%;
        height: 144px;
        object-fit: cover;
        border-radius: 4px 4px 0 0;
      }
      &-bar {
        display: flex;
        margin-top: 8px;
      }
      &-chk {
        margin-left: 5px;
      }
      &-title {
        overflow: hidden;
        text-overflow: ellipsis;
        -o-text-overflow: ellipsis;
        white-space:nowrap;
      }
    }
    &-bottom {
      text-align: right;
      padding: 10px 10px 0 10px;
    }
    &-btn {
      margin: 10px;
      .ivu-btn {
        margin-left: 10px;
      }
    }
  }
  .card-icon {
    position: absolute;
    cursor: pointer;
    top: 50%;
    left: 50%;
    transform: translate3d(-50%, -50%, 0);
    font-size: 50px !important;
    color: #fff;
  }
  .input-wrap {
    width: 300px;
    display: flex;
    justify-content: left;
    align-items: center;
    .label {
      width: 80px;
    }
  }
  .set-width {
    input {
      width: 200px !important;
    }
  }

  /* 环球定制 */
  #app > div.wly-picker > div.wly-picker-bar > div.wly-picker-bar-left > div > div.ivu-select-dropdown {
    max-height: 450px;
  }
</style>
