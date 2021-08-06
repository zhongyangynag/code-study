import Vue from 'vue'
import Router from 'vue-router'
import Home from './views/Home.vue'
import Picker from './views/Picker'

Vue.use(Router)

export default new Router({
  mode: 'history',
  base: window.path,
  routes: [
    {
      path: '*',
      redirect: '/media/index/image'
    },
    {
      path: `/media/index/:type`,
      name: 'media',
      component: Home
    },
    {
      path: '/media/picker/:type',
      name: 'picker',
      component: Picker
    }
  ]
})
