import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)

export default new Vuex.Store({
  state: {
    sourceId: '',
    categoryId: '',
    categoryList: [],
    categoryPagination: {
      total: 0
    },
    mediaType: 'image',
    checkList: [],
    orderBy: 'desc',
    extras: [],
    subtype: '*',
    attachmentType: null
  },
  getters: {
    sourceId: state => {
      return state.sourceId
    },
    categoryId: state => {
      return state.categoryId
    },
    categoryList: state => {
      return state.categoryList
    },
    categoryPagination: state => {
      return state.categoryPagination
    },
    mediaType: state => {
      return state.mediaType
    },
    checkList: state => {
      return state.checkList
    },
    orderBy: state => {
      return state.orderBy
    },
    extras: state => {
      return state.extras
    },
    subtype: state => {
      return state.subtype
    },
    attachmentType: state => {
      return state.attachmentType
    }
  },
  mutations: {
    changeSource (state, id) {
      state.sourceId = id
    },
    changeCategory (state, id) {
      state.categoryId = id
    },
    fillCategoryList (state, list) {
      state.categoryList = list
    },
    fillCategoryPagination (state, pagination) {
      state.categoryPagination = pagination
    },
    changeMeidaType (state, type) {
      state.mediaType = type
    },
    addCheckList (state, data) {
      state.checkList.push(data)
    },
    remoteCheckList (state, id) {
      return state.checkList.filter(item => { item.id = id })
    },
    changeOrderBy (state, order) {
      state.orderBy = order
    },
    addExtras (state, obj) {
      state.extras.push(obj)
    },
    setSubType (state, subtype) {
      state.subtype = subtype || '*'
    },
    setAttachmentType (state, type) {
      state.attachmentType = type
    }
  },
  actions: {

  }
})
