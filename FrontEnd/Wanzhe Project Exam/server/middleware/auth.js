//登录验证中间件
module.exports = options => {
  return async (req, res, next) => {
    const jwt = require('jsonwebtoken')
    const AdminUser = require('../models/AdminUser')
    const assert = require('http-assert') //用做断言抛出异常
    //进行分割获取,因为之前前端有Bearer ,所以分割一下
    const token = String(req.headers.authorization || '')
      .split(' ')
      .pop()
    //token不能为空,否则jwt.verify无法进行
    assert(token, 401, '请先登录')

    //token解密出来获取到id,req.app与index.js中的app是等同的
    const { id } = jwt.verify(token, req.app.get('secret'))
    assert(id, 401, '请先登录')

    req.user = await AdminUser.findById(id)
    assert(req.user, 401, '请先登录')
    await next()
  }
}
