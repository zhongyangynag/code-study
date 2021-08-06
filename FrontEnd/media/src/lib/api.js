import request from '@/lib/request'

const mediaPrefix = window.path + '/media/admin-api'
const categoryPrefix = window.path + '/media-category/category-api'

const media = {
  save (data) {
    return request({ url: `${mediaPrefix}/save`, method: 'post', data: data })
  },
  list (data) {
    return request({ url: `${mediaPrefix}/list`, method: 'post', data: data })
  },
  detail (data) {
    return request({ url: `${mediaPrefix}/detail`, method: 'post', data: data })
  },
  del (data) {
    return request({ url: `${mediaPrefix}/del`, method: 'post', data: data })
  },
  batchdel (data) {
    return request({ url: `${mediaPrefix}/batchdel`, method: 'post', data: data })
  },
  multiUpdate (data) {
    return request({ url: `${mediaPrefix}/multi_update`, method: 'post', data: data })
  }
}

const category = {
  list (data) {
    return request({ url: `${categoryPrefix}/list`, method: 'post', data: data })
  },
  save (data) {
    return request({ url: `${categoryPrefix}/save`, method: 'post', data: data })
  },
  del (data) {
    return request({ url: `${categoryPrefix}/del`, method: 'post', data: data })
  }
}

export {
  media,
  category
}
