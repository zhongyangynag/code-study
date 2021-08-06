<template>
  <div class="wly-media-list">
    <div class="wly-media-operate">
      <div class="operate-left">
        <Checkbox v-model="allCheck" @on-change="selectAll">全选</Checkbox>
        <Poptip placement="bottom" width="300">
          <Button :disabled="isSelected">移动分组</Button>
          <div class="category-list" slot="content">
            <a
              href="javascript:;"
              @click="moveCategory(category._id)"
              v-for="(category, index) in categoryList"
              :key="index"
            >{{category.category_name}}</a>
          </div>
        </Poptip>
        <Button :disabled="isSelected" @click="deleteMedias">删除</Button>
      </div>
      <div class="operate-right">
        <Page
          :total="pagination.total"
          :page-size="pagination.page_size"
          @on-change="changePage"
          show-elevator
          :current="pagination.current_page"
        />
      </div>
    </div>
    <waterfall v-if="list.length > 0" align="center" :line-gap="310 + 20" :watch="list">
      <!-- each component is wrapped by a waterfall slot -->
      <waterfall-slot
        class="wly-waterfall-item"
        v-for="(item, index) in list"
        :width="item.width"
        :height="item.height"
        :order="index"
        :key="item.index"
        move-class="item-move"
      >
        <CheckboxGroup v-model="selectList">
          <div class="wly-media-card" :style="item.style" :index="item.index">
            <div
              class="card-img-figure"
              :style="{ width: `${item.width}px`, height: '174px' }"
              @click="showPreview(index)"
            >
              <span :class="cardIcon" @click="mediaPlay(item)"></span>
              <wii-image :width="`${item.width}px`" height="174px" :src="item.img_url">
                <Tag v-if="item.category_name && item.category_name !== ''" class="img-tag" :color="tagColor" disable>{{item.category_name}}</Tag>
              </wii-image>
            </div>
            <div class="wly-media-card-desc">
              <div class="wly-media-card-bar">
                <Checkbox :label="item._id" class="card-checkbox"></Checkbox>
                <div class="wly-media-card-title">{{item.name}}</div>
              </div>
              <div class="wly-media-card-tools">
                <a @click="showEditor(item)" class="btn-edit" href="javascript:;">
                  <span class="icon-edit"></span>
                </a>
                <a @click="downloadItem(item)" class="btn-download" href="javascript:;">
                  <span class="icon-download"></span>
                </a>
                <a @click="deleteItem(item)" class="btn-delete" href="javascript:;">
                  <span class="icon-remove"></span>
                </a>
              </div>
            </div>
          </div>
        </CheckboxGroup>
      </waterfall-slot>
    </waterfall>
    <div v-else class="wly-waterfall-nodata">
      <span v-if="isLoading">素材加载中…</span>
      <span v-else>该分组下没有找到任何资源</span>
    </div>
    <Modal
      :title="`${typeName}编辑`"
      v-model="editorShow"
      width="880"
      @on-ok="mediaEdit"
      :mask-closable="false"
    >
      <i-form :model="mediaInfo" :rules="ruleValidate" :label-width="80">
        <FormItem :label="typeName">
          <div class="image-figure">
            <span :class="cardIcon" v-if="mediaType !== 'attachment'" @click="mediaPlay(mediaInfo)"></span>
            <wii-image v-if="editorShow" width="260px" height="140px" :src="mediaInfo.img_url"></wii-image>
          </div>
        </FormItem>
        <FormItem v-if="mediaType !== 'image'" label="封面图片">
          <wly-uploader :isCover="true" :fileId="mediaInfo.file_id" @done="showCover"></wly-uploader>
        </FormItem>
        <FormItem :label="`${typeName}名称`" prop="name">
          <Input v-model="mediaInfo.name" placeholder="请输入素材名称" />
        </FormItem>
        <FormItem label="选择分组">
          <RadioGroup v-model="mediaInfo.category_id">
            <category-btn></category-btn>
            <Radio
              :label="category._id"
              v-for="(category, index) in categoryList"
              :key="index"
            >
              <span>{{category.category_name}}</span>
            </Radio>
          </RadioGroup>
        </FormItem>
        <div v-if="mediaType === 'image'">
          <!-- <FormItem label="版本">
              <Input v-model="mediaInfo.version" placeholder="请输入版本"/>
          </FormItem>-->
          <FormItem label="尺寸">{{mediaInfo.dimension}}</FormItem>
          <FormItem label="存储大小">{{mediaInfo.size}}</FormItem>
          <FormItem label="更新时间">{{mediaInfo.update_time}}</FormItem>
        </div>
        <div v-else>
          <FormItem label="存储大小">
            <!-- <Input v-model="mediaInfo.size" placeholder="请输入存储大小"/> -->
            {{mediaInfo.size}}
          </FormItem>
          <FormItem label="更新时间">
            <!-- <Input v-model="mediaInfo.update_time" placeholder="请输入更新时间"/> -->
            {{mediaInfo.update_time}}
          </FormItem>
          <FormItem  v-if="mediaType !== 'attachment'" label="语种">
            <!-- <Input v-model="mediaInfo.language" placeholder="请输入语种"/> -->
            <i-select v-model="mediaInfo.language" style="width:200px">
              <i-option
                v-for="item in languageList"
                :value="item.value"
                :key="item.value"
              >{{ item.label }}</i-option>
            </i-select>
          </FormItem>
        </div>
      </i-form>
    </Modal>

    <Modal
      :title="`${typeName}查看`"
      v-model="playShow"
      @on-cancel="playCancel"
      @on-ok="ok"
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
import Waterfall from 'vue-waterfall/lib/waterfall'
import WaterfallSlot from 'vue-waterfall/lib/waterfall-slot'
import { media } from '@/lib/api'
import { merge, cloneDeep } from 'lodash'
import { downloadImage, getImageSize, downloadBinary, formatImageData } from '@/lib/utils'
import { mapGetters } from 'vuex'
import WiiLoader from 'wiiloader/index.js'
const files = [
  '//imgcache.qq.com/open/qcloud/video/tcplayer/tcplayer.css',
  '//imgcache.qq.com/open/qcloud/video/tcplayer/libs/hls.min.0.12.4.js',
  '//imgcache.qq.com/open/qcloud/video/tcplayer/libs/dash.all.min.2.9.3.js',
  '//imgcache.qq.com/open/qcloud/video/tcplayer/tcplayer.min.js'
]
export default {
  name: 'wly-media-list',
  data () {
    return {
      pageSize: 10,
      tagColor: 'blue',
      saveLoading: true,
      isLoading: true,
      list: [],
      selectList: [],
      editorShow: false,
      playShow: false,
      mediaInfo: {},
      mediaLoading: false,
      allCheck: false,
      pagination: {
        current_page: 1,
        total: 0,
        page_size: 10
      },
      languageList: [
        {
          label: '中文',
          value: 'chinese'
        },
        {
          label: '英文',
          value: 'english'
        }
      ],
      ruleValidate: {
        name: [{ required: true, message: '名称不能为空', trigger: 'blur' }]
      }
    }
  },
  components: {
    Waterfall,
    WaterfallSlot
  },
  async mounted () {
    this.pageSize = this.$route.query.page_size || 20
    this.tagColor = window.config.theme || 'blue'
    this.$bus.$on('media.list', (isChangeCategory) => {
      if (isChangeCategory) { // 重新选择分类，需要重置全选
        this.allCheck = false
        this.allCheckArr = []
        this.selectList = []
      }
      this.getList({ page_size: this.pageSize })
    })
    await WiiLoader.load(files)
  },
  computed: {
    isSelected () {
      return this.selectList.length === 0
    },
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
      if (mediaType === 'image' || mediaType === 'attachment') {
        className = ''
      }
      return `${className}`
    },
    ...mapGetters(['sourceId', 'categoryList', 'categoryId', 'mediaType', 'orderBy'])
  },
  methods: {
    selectAll (isAll) {
      const selectedList = this.selectList
      if (isAll) {
        const newList = this.list.map(item => {
          return item._id
        })
        this.selectList = Array.from(new Set(selectedList.concat(newList)))
      } else {
        this.selectList = selectedList.filter(selected => {
          return !this.list.some(item => item._id === selected)
        })
      }
    },
    getList (params = {}) {
      this.list = []
      this.isLoading = true
      let data = {
        media_type: this.mediaType,
        sort_create_time: this.orderBy,
        category_id: this.categoryId,
        source_id: this.sourceId
      }
      params = merge({}, data, params)
      media.list(params).then(({ list, pagination }) => {
        console.log('list', list)
        this.$nextTick(() => {
          this.isLoading = false
          this.list = list.map(item => {
            let nameArray = this.categoryList.filter(categoryItem => {
              return item.category_id === categoryItem._id
            })
            let categoryName
            if (nameArray && nameArray.length > 0) {
              categoryName = nameArray[0].category_name
            }
            return merge(item, { width: 310, height: 280, category_name: categoryName })
          })
          const allChecked = this.list.every(item => {
            return this.selectList.indexOf(item._id) >= 0
          })
          this.handleAllCheck(allChecked)
          this.pagination = pagination
        })
      })
    },
    showPreview (index) {
      if (this.mediaType === 'image') {
        formatImageData(this.list, imgs => {
          this.$bus.$emit('photoswipe.shown', imgs, index)
        })
      }
    },
    async showEditor (info) {
      this.editorShow = true
      if (this.mediaType === 'image') {
        let img = await getImageSize(info.img_url)
        info.dimension = `${img.width}X${img.height}`
      }
      this.mediaInfo = cloneDeep(info)
    },
    downloadItem ({ img_url, play_url, file_type, name, attachment_url }) {
      if (this.mediaType === 'image') {
        downloadImage(img_url, name)
      } else {
        if (play_url || attachment_url) {
          downloadBinary(play_url || attachment_url, name)
        } else {
          this.$Message.error('没有可下载的内容，请重新上传!')
        }
      }
    },
    deleteItem ({ _id, name }) {
      this.$Modal.confirm({
        title: '删除提示',
        content: `确定要删除"${name}"吗？`,
        loading: true,
        onOk: () => {
          media.del({ _id: _id }).then(res => {
            this.$Modal.remove()
            this.$bus.$emit('media.list')
            this.$bus.$emit('category.list')
          })
        }
      })
    },
    reset () {
      this.selectList = []
      this.allCheck = false
      this.$Message.success('成功将素材加到分组')
    },
    moveCategory (categoryId) {
      media
        .multiUpdate({
          _ids: this.selectList,
          category_id: categoryId
        })
        .then(res => {
          document.querySelector('body').click()
          this.reset()
          this.$bus.$emit('media.list')
          this.$bus.$emit('category.list')
        })
    },
    deleteMedias () {
      if (this.selectList.length > 0) {
        this.$Modal.confirm({
          title: '批量删除提示',
          content: `确定要删除选中的素材吗？`,
          loading: true,
          onOk: () => {
            media.batchdel({ _ids: this.selectList }).then(res => {
              this.reset()
              this.$Modal.remove()
              this.$bus.$emit('media.list')
              this.$bus.$emit('category.list')
            })
          }
        })
      } else {
        this.$Message.error('还没有选中任何图片')
      }
    },
    mediaEdit () {
      let { name } = this.mediaInfo
      if (name) {
        delete this.mediaInfo.size
        delete this.mediaInfo.update_time
        delete this.mediaInfo.create_time
        media.save(this.mediaInfo).then(() => {
          this.$bus.$emit('media.list')
          this.$bus.$emit('category.list')
        })
      } else {
        this.$Message.error('名称不能为空')
        return false
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
    ok () {
      if (this.mediaType === 'video') {
        this.player.dispose()
      }
    },
    playCancel () {
      this.playShow = false
      if (this.mediaType === 'video') {
        this.player.dispose()
      }
    },
    changePage (page) {
      this.getList({ page_size: this.pageSize, p: page })
      this.allCheck = false
    },
    showCover (data) {
      // this.mediaInfo.img_url = data.cover.url
      console.log('cover data', data)
      this.mediaInfo.img_url = (data.cover && data.cover.url) || (data.data && data.data.img_url)
    },
    handleAllCheck (allCheck) {
      this.allCheck = allCheck
    }
  },
  watch: {
    selectList (selectList) {
      console.log(selectList)
      const allChecked = this.list.every(item => {
        return selectList.indexOf(item._id) >= 0
      })
      this.handleAllCheck(allChecked)
    }
  }
}
</script>

<style lang="less">
.item-move {
  transition: all 0.5s cubic-bezier(0.55, 0, 0.1, 1);
  -webkit-transition: all 0.5s cubic-bezier(0.55, 0, 0.1, 1);
}
.editor-img {
  width: 260px;
  height: 140px;
  border-radius: 4px;
  object-fit: cover;
}
.modal-video,
.modal-audio {
  width: 100%;
}
.modal-video {
  max-height: 390px;
}
.wly-media-list {
  width: 100%;
  // height: 100%;
  overflow-y: auto;
  .ivu-checkbox + span {
    display: none;
  }
}
.wly-media-operate {
  padding: 20px 25px 10px 25px;
  display: flex;
  .operate-left {
    flex: 1;
  }
  .category-list {
    overflow: hidden;
    a {
      display: block;
      float: left;
      color: #444;
      padding: 5px 15px;
    }
  }
  .ivu-checkbox {
    margin-right: 5px;
  }
  .ivu-checkbox-wrapper {
    margin-right: 20px;
  }
  .ivu-btn {
    margin-right: 15px;
  }
}
.wly-waterfall-nodata {
  text-align: center;
  line-height: 400px;
  font-size: 14px;
}
.wly-waterfall-item {
  overflow: hidden;
  img {
    border-radius: 4px 4px 0 0;
    &.card-img {
      width: 100%;
      object-fit: cover;
    }
    &.card-no-img {
      padding-top: 20px;
    }
  }
  .wly-media-card {
    border-radius: 4px;
    border: 1px solid rgba(232, 234, 236, 1);
    overflow: hidden;
    margin: 10px;
    .card-img-figure {
      position: relative;
      text-align: center;
      background: #f0f0f0;
    }
    .icon-play {
      position: absolute;
      cursor: pointer;
      top: 50%;
      left: 50%;
      transform: translate3d(-50%, -50%, 0);
    }
    &-desc {
      padding: 10px 15px 0 15px;
    }
    &-bar {
      display: flex;
      height: 24px;
      line-height: 24px;
      .card-checkbox {
        vertical-align: middle;
      }
    }
    &-title {
      flex: 1;
      font-size: 14px;
      color: #464c5b;
      overflow: hidden;
      text-overflow: ellipsis;
      white-space: nowrap;
    }
    &-tools {
      padding: 20px 0;
      display: flex;
      justify-content: space-between;
      a {
        display: inline-block;
        color: #464c5b;
        text-align: center;
        flex: 1;
      }
      .ivu-icon {
        font-size: 20px;
      }
    }
  }
}
.image-figure {
  position: relative;
  width: 260px;
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
.img-tag {
  position: absolute;
  top: 0;
  right: 0;
}
wii-image {
  position: relative;
}
</style>
