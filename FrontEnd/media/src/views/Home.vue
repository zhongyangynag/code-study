<template>
  <div class="wly-home">
    <div class="wly-home-sider">
      <wly-category></wly-category>
    </div>
    <div class="wly-home-content">
      <wly-toolbar></wly-toolbar>
      <wly-media-list></wly-media-list>
    </div>
  </div>
</template>

<script>
import RocketCookie from '@/lib/cookie'
export default {
  name: 'home',
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
  }
}
</script>

<style lang="less">
  .wly-home {
    height: 100%;
    display: flex;
    &-sider {
      height: 100%;
    }
    &-content {
      flex: 1;
      display: flex;
      flex-direction: column;
    }
  }
</style>
