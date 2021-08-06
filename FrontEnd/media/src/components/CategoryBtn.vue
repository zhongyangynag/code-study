<template>
  <div class="category-btn">
    <Poptip v-model="poptipVisible" content="content" placement="top-start">
      <div class="category-group" slot="content">
        <i-form label-position="top">
          <FormItem label="分组名称">
            <Input v-model="name" placeholder="请输入分组名称"/>
          </FormItem>
          <FormItem class="form-buttons">
            <Button @click="categoryCancel">取消</Button>
            <Button @click="categorySubmit" :loading="categoryCreateLoading" type="primary">确定</Button>
          </FormItem>
        </i-form>
      </div>
      <Button><span class="icon-add"></span> 新建分组</Button>
    </Poptip>
    <Modal
      v-model="maxCategoryLengthModal"
      title="提示">
      <p>最大支持 {{maxCategoryLength}} 个分组</p>
    </Modal>
  </div>
</template>

<script>
import { category } from '@/lib/api'
import { mapGetters } from 'vuex'
import commonConfig from '@/configs/common'
export default {
  name: 'category-btn',
  data () {
    return {
      name: '',
      poptipVisible: false,
      categoryCreateLoading: false,
      maxCategoryLengthModal: false,
      maxCategoryLength: commonConfig.maxCategoryLength
    }
  },
  computed: {
    ...mapGetters(['categoryPagination', 'sourceId', 'categoryId', 'categoryList', 'mediaType'])
  },
  methods: {
    categoryCancel () {
      this.poptipVisible = false
    },
    categorySubmit () {
      let { name } = this
      if (name && name !== '') {
        this.categoryCreateLoading = true

        //
        if (this.$route.query.maxCategoryLength) {
          this.maxCategoryLength = this.$route.query.maxCategoryLength - 0
        }

        // 检查分数数量是否超过限制
        category
          .list({ source_id: this.sourceId, media_type: this.mediaType, p: 1, page_size: this.maxCategoryLength })
          .then(({ list, pagination }) => {
            console.log(list, pagination)
            // this.list = list
            this.$store.commit('fillCategoryList', list)
            this.$store.commit('fillCategoryPagination', pagination)
            this.$bus.$emit('media.list')

            this.$nextTick(() => {
              if (this.categoryPagination.total >= this.maxCategoryLength) {
                this.maxCategoryLengthModal = true
                this.name = ''
                this.poptipVisible = false
                this.categoryCreateLoading = false
              } else {
              // 创建新分组
                category.save({ category_name: name, source_id: this.sourceId }).then(res => {
                  this.name = ''
                  this.poptipVisible = false
                  this.categoryCreateLoading = false
                  this.$bus.$emit('category.list')
                })
              }
            })
          })
      } else {
        this.$Message.error('输入正确的分组名称!')
      }
    }
  }
}
</script>

<style lang="less">
  .category-btn {
    .category-group {
      width: 280px;
      box-sizing: border-box;
      text-align: left;
    }
    .ivu-form-item{
      text-align: left;
      margin: 20px 0;
      .ivu-input{
        width: 100%;
      }
    }
    .form-buttons{
      text-align: right;
      .ivu-btn {
        margin-left: 15px;
      }
    }
  }
</style>
