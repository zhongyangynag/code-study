//资源请求中间件
module.exports = options => {
  return async (req, res, next) => {
    const modelNmae = require("inflection").classify(req.params.resource);
    req.Model = require(`../models/${modelNmae}`);
    await next();
  };
};
