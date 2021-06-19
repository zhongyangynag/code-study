module.exports = app => {
  const express = require("express");
  //下面两个引入都是与登录验证有关的,通用接口里面是对于接口的增删改查
  const jwt = require("jsonwebtoken");
  const AdminUser = require("../../models/AdminUser");
  const assert = require("http-assert"); //用做断言抛出异常
  const router = express.Router({
    mergeParams: true
  }); //合并URL参数,因为此参数为动态参数,通过合并才能访问到下方app.use的路径

  //添加资源
  router.post("/", async (req, res) => {
    const model = await req.Model.create(req.body);
    res.send(model);
  });
  //资源列表
  router.get("/", async (req, res) => {
    let queryOptions = {};
    if (req.Model.modelName === "Category") {
      //modelName为模型上的一个属性
      queryOptions.populate = "parents";
    } else if (req.Model.modelName == "Article") {
      queryOptions.populate = "categories";
    }
    //因为是通用接口,所以这儿的populate需要设置为选择进行的用法
    const items = await req.Model.find()
      .setOptions(queryOptions) //通过setOptions进行选择进行populate方法
      .limit(10);
    res.send(items);
  });
  //获取资源
  router.get("/:id", async (req, res) => {
    const model = await req.Model.findById(req.params.id);
    res.send(model);
  });
  //修改资源
  router.put("/:id", async (req, res) => {
    const model = await req.Model.findByIdAndUpdate(req.params.id, req.body);
    res.send(model);
  });
  //删除资源
  router.delete("/:id", async (req, res) => {
    await req.Model.findByIdAndDelete(req.params.id);
    res.send({
      success: true
    });
  });
  //登录校验中间件,要进行请求头的验证
  const authMiddleware = require("../../middleware/auth");
  //资源获取中间件,用于对传入的请求进行解析
  const resourceMiddleware = require("../../middleware/resource");

  app.use(
    //写成一个中间件的形式
    "/admin/api/rest/:resource",
    authMiddleware(),
    resourceMiddleware(),
    router
  );

  //上面是关于接口请求各种分类数据的api,下面是一些特殊的请求api
  //请求上传文件的api
  const multer = require("multer");
  //dest代表的是上传的文件要保存在什么地方,上传文件后就会自动进行保存
  const upload = multer({ dest: __dirname + "/../../uploads" });

  //upload.single()代表接收单个file文件,中间加了两个中间件
  app.post(
    "/admin/api/upload",
    authMiddleware(),
    upload.single("file"),
    async (req, res) => {
      //req.file是multer中间件为其加上的
      const file = req.file;
      //将得到的file生成一个客户端能够认识的地址返回给客户端,注意地址一定是服务端地址
      file.url = `http://localhost:3000/uploads/${file.filename}`;
      res.send(file);
    }
  );

  app.post("/admin/api/login", async (req, res) => {
    const { username, password } = req.body;
    //1.根据用户名找用户
    //因为前面默认是不取出password,这里在校验面的时候必须要取出,使用select("+passwrod")
    const user = await AdminUser.findOne({ username }).select("+password");
    //抛出异常,直接传递到最后一个错误处理函数中
    assert(user, 422, "用户不存在");

    //2.校验密码
    const isValid = require("bcrypt").compareSync(password, user.password);
    assert(isValid, 422, "密码输入错误");
    //3.返回token
    //这个可以放多个数据
    // jwt.sign({ _id: user.id, id: user.id, username: user.username });
    //因为是根据id进行查找,所以这里只放用户的id
    //app.get得到之前在index.js里面设置的密钥
    const token = jwt.sign({ id: user._id }, app.get("secret"));
    res.send({ token });
  });

  //统一的错误处理函数
  app.use(async (err, req, res, next) => {
    console.log(err);
    res.status(err.statusCode || 500).send({
      message: err.message
    });
  });
};
