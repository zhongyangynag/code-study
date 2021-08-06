<template>
  <div id="app">
    <r-photo-swipe></r-photo-swipe>
    <router-view></router-view>
  </div>
</template>

<script>
export default {
  name: 'app',
  components: {},
  data () {
    return {
    }
  },
  created () {
    this.$bus.$on('media.error.show', msg => {
      // console.log(`发过来的消息${msg}..........`)
    })
    let querys = this.$route.query
    if (querys.subtype) {
      this.$store.commit('setSubType', querys.subtype)
    }
    if (querys.attachmenttype) {
      this.$store.commit('setAttachmentType', querys.attachmenttype)
    }
  }
}
</script>

<style>
html,
body,
#app {
  height: 100%;
  overflow: hidden;
}

::-webkit-scrollbar {
  width: 5px;
}

::-webkit-scrollbar-track {
  border-radius: 5px;
  background-color: #eee;
}

::-webkit-scrollbar-thumb {
  border-radius: 5px;
  background: rgba(168, 168, 168, 0.5);
}
</style>
