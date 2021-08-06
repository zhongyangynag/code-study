import RocketBus from '../lib/bus'
import request from '../lib/request'

export default {
  data () {
    return {
      uuid: Math.random().toString(36).substring(3, 8)
    }
  },
  beforeCreate () {
    this.$bus = RocketBus(this)
    this.$request = request
  }
}
