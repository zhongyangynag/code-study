<template>
  <div class="wly-category">
    <Menu
      ref="siders"
      class="wly-category-menu"
      :active-name="categoryId"
      width="160px"
      @on-select="changeCategory">
      <MenuItem v-for="(menu, index) in categoryList" :key="index" :name="menu._id">
        {{menu.category_name}}（{{menu.count||0}}）
        <Icon
          v-if="menu.can_del === 1"
          @click.stop="categoryDelete(menu)"
          class="group-delete"
          type="ios-close"
        />
      </MenuItem>
    </Menu>
    <div class="wly-category-options">
      <category-btn></category-btn>
    </div>
  </div>
</template>

<script>
import { category } from '@/lib/api'
import { mapGetters, mapMutations } from 'vuex'
import commonConfig from '@/configs/common'

export default {
  name: 'wly-category',
  data () {
    return {
      name: '',
      list: [],
      maxCategoryLength: commonConfig.maxCategoryLength
    }
  },
  mounted () {
    this.getList()
    this.$bus.$on('category.list', this.getList)
  },
  computed: {
    ...mapGetters(['sourceId', 'categoryId', 'categoryList', 'mediaType'])
  },
  methods: {
    getList () {
      //
      if (this.$route.query.maxCategoryLength) {
        this.maxCategoryLength = this.$route.query.maxCategoryLength
      }

      category
        .list({ source_id: this.sourceId, media_type: this.mediaType, p: 1, page_size: this.maxCategoryLength })
        .then(({ list }) => {
          // this.list = list
          this.$store.commit('fillCategoryList', list)
          this.$bus.$emit('media.list')
          this.$nextTick(() => {
            this.$refs.siders.updateActiveName()
          })
        })
    },
    ...mapMutations(['fillCategoryList']),
    creeateCategory () {},
    categoryDelete ({ _id, category_name }) {
      this.$Modal.confirm({
        title: '分组删除提示',
        content: `确认要删除分组"${category_name}"吗？`,
        loading: true,
        onOk: () => {
          category.del({ _id: _id }).then(res => {
            this.$Modal.remove()
            // if (this.categoryId === _id) {
            this.$store.commit('changeCategory', 1)
            this.$bus.$emit('category.list')
            // }
            // this.$bus.$emit('media.list')
          })
        }
      })
    },
    changeCategory (categoryId) {
      this.$store.commit('changeCategory', categoryId)
      this.$bus.$emit('media.list', true)
    }
  }
}
</script>

<style lang="less">
.wly-category {
  height: 100%;
  display: flex;
  flex-direction: column;
  border-right: solid 1px #ccc;
  &-menu {
    // flex: 1;
    overflow-y: auto;
    .ivu-menu-item {
      overflow: hidden;
      text-overflow: ellipsis;
      white-space: nowrap;
      .group-delete {
        font-size: 26px;
        position: absolute;
        top: 12px;
        right: 0px;
        display: none;
      }
      &:hover {
        .group-delete {
          display: block;
        }
      }
    }
  }
  &-options {
    // border-top: solid 1px #ccc;
    // border-bottom: solid 1px #ccc;
    // border-right: solid 1px #ccc;
    padding: 15px 0;
    width: 100%;
    text-align: center;
  }
}
</style>
