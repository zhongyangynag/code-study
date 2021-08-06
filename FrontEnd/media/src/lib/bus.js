import $Vue from 'vue'

let Vue = $Vue

if (typeof window !== 'undefined' && window.Vue) {
  Vue = window.Vue
}

// 事件列表
const cacheList = {}
const Bus = new Vue()

// 卸载事件
const destroyHandler = function () {
  const currentEvent = cacheList[this._uid]
  if (typeof currentEvent === 'undefined') {
    return
  }
  for (let type in currentEvent) {
    const key = Array.isArray(type) ? type.join(',') : type
    Bus.$off(type, currentEvent[key])
  }
  delete cacheList[this._uid]
}

const RocketBus = vm => {
  const destroyed = vm.$options.destroyed
  const uid = vm._uid
  cacheList[uid] = {}
  !destroyed.includes(destroyHandler) && destroyed.push(destroyHandler)
  return {
    $on: (type, handler) => {
      const key = Array.isArray(type) ? type.join(',') : type
      cacheList[uid][key] = handler
      Bus.$on(key, handler)
    },
    $off: (type, handler) => {
      if (!type) {
        delete cacheList[uid]
        Bus.$off()
        return
      }
      const key = Array.isArray(type) ? type.join(',') : type
      delete cacheList[uid][key]
      Bus.$off(type, handler)
    },
    $once: (...args) => Bus.$once(...args),
    $emit: (...args) => Bus.$emit(...args)
  }
}

RocketBus.$emit = (...args) => Bus.$emit(...args)
RocketBus.$on = (...args) => Bus.$on(...args)

export default RocketBus
export { Bus }
