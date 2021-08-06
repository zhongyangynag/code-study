import flyio from 'flyio'

const NET_ERROR_MSG = '请求失败，请检查网络'

const request = options => {
  let conf = {
    url: '',
    method: 'get',
    data: {},
    customError: false,
    ...options
  }

  let pm = flyio.request(conf.url, conf.data, conf)
    .then(xhr => {
      if (xhr) {
        // 临时增加通知弹窗关闭
        console.log('xhr', xhr)
        let res = xhr.data
        if (res) {
          let rs = res
          if (conf.customError || rs.code === 0 || rs.ret === 0) {
            return rs.data
          } else if (rs) {
            return Promise.reject(new Error(rs.msg))
          } else {
            return Promise.reject(new Error(`请求失败(${rs.code})`))
          }
        } else {
          return Promise.reject(new Error(`${NET_ERROR_MSG}(${xhr.status})`))
        }
      } else {
        return Promise.reject(new Error('未取得xhr对象'))
      }
    })
    .catch(err => {
      let statusMsg = ''
      if (err && err.response && err.response.status) {
        statusMsg = `(${err.response.status})`
      }
      if (statusMsg) {
        return Promise.reject(new Error(`${NET_ERROR_MSG}${statusMsg}`))
      } else {
        return Promise.reject(err)
      }
    })

  return pm
}

export default request
