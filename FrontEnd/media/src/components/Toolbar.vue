<template>
  <div class="wly-toolbar">
    <div class="wly-toolbar-left">
      <i-select v-model="orderBy" :clearable="true" style="width:200px" placeholder="按上传时间顺序">
        <i-option v-for="item in orderList" :value="item.value" :key="item.value">{{ item.label }}</i-option>
      </i-select>
    </div>
    <div class="wly-toolbar-right">
      <wly-uploader></wly-uploader>
    </div>
  </div>
</template>

<script>
export default {
  name: 'wly-toolbar',
  data () {
    return {
      orderList: [{
        label: '上传时间正序',
        value: 'asc'
      }, {
        label: '上传时间倒序',
        value: 'desc'
      }],
      tag: '',
      tagList: []
    }
  },
  computed: {
    orderBy: {
      get () {
        return this.$store.state.orderBy
      },
      set (orderBy) {
        this.$store.commit('changeOrderBy', orderBy)
        this.$bus.$emit('media.list')
      }
    }
  }
}
</script>

<style lang="less">
  .wly-toolbar {
    display: flex;
    padding: 10px;
    border-bottom: solid 1px #DCDEE2;
    &-left {
      flex: 1;
    }
    &-right {
      width: 130px;
    }
  }
</style>
