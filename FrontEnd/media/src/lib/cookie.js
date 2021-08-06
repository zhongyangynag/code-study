const isArray = Array.isArray || function (value) {
  return Object.prototype.toString.call(value) === '[object Array]'
}

const getKeys = Object.keys || function (obj) {
  var keys = []; var key = ''
  for (key in obj) {
    if (obj.hasOwnProperty(key)) keys.push(key)
  }
  return keys
}

const isPlainObject = (value) => {
  return !!value && Object.prototype.toString.call(value) === '[object Object]'
}

const timeDiff = (time) => {
  var timeArr = time.split(':')
  for (var i = 0, len = timeArr.length; i < len; i++) {
    if (timeArr[i].split('')[0] === 0) {
      timeArr[i] = timeArr[i].split('')[1]
    }
  }
  var now = new Date()
  var h = parseInt(timeArr[0]) - now.getHours()
  var m = parseInt(timeArr[1]) - now.getMinutes()
  var s = parseInt(timeArr[2]) - now.getSeconds()
  return (h * 60 * 60 + m * 60 + s) * 1000
}

class RocketCookie {
  get (name) {
    return this.getAll()[name] || null
  }

  set (name, value, options) {
    let opt = isPlainObject(options) ? options : { expires: options }
    let expires = opt.expires !== undefined ? opt.expires : ''
    let expiresType = typeof expires
    if (expiresType === 'string' && expires !== '') {
      var regexp = /^([01]\d|2[0-3]):[0-5]\d:([0-5]\d)$/
      // 验证时间格式：hh:mm:ss
      if (regexp.test(expires)) {
        expires = new Date(+new Date() + timeDiff(expires))
        // 设置过期时间: 例如：23:00:00
      } else {
        expires = new Date(expires)
        // 设置过期时间，例如：2018-10-02 16:14:22
      }
    } else if (expiresType === 'number') {
      expires = new Date(+new Date() + 1e3 * 60 * 60 * 24 * expires)
      // 设置 expires 天过期
    }
    if (expires !== '' && 'toGMTString' in expires) {
      expires = '; expires=' + expires.toGMTString()
    }
    let path = '; path=' + (opt.path ? opt.path : '/')
    // 设置路径
    let domain = opt.domain ? '; domain=' + opt.domain : ''
    // 设置域
    let secure = opt.secure ? '; secure' : ''
    // 设置安全措施，为 true 则直接设置，否则为空
    document.cookie = name + '=' + encodeURI(value) + expires + path + domain + secure
  }

  remove (names) {
    names = isArray(isArray) ? names : [names]
    names.forEach(name => {
      this.set(name, '', -1)
    })
    return names
  }

  clear () {
    return this.remove(getKeys(this.getAll()))
  }

  getAll () {
    let result = {}
    if (document.cookie) {
      let cookies = document.cookie.split('; ')
      cookies.forEach((cookie) => {
        let [name, value] = cookie.split('=')
        result[name] = value
      })
    }
    return result
  }
}

export default RocketCookie
