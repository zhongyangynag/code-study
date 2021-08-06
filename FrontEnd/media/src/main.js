import Vue from 'vue'
import App from './App.vue'
import router from './router'
import store from './store'
import './plugins/iview.js'
import './plugins/component'
import baseMix from '@/mixins/base'
import './assets/fonts.less'

Vue.config.productionTip = false

Vue.mixin(baseMix)

const theme = window.config.theme || 'reset'
const styleUrl = theme + '.less'
import(`./assets/${styleUrl}`).then(_ => {
  new Vue({
    router,
    store,
    render: h => h(App)
  }).$mount('#app')
})
