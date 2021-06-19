const mongoose = require("mongoose");
const Schema = mongoose.Schema;

const schema = new Schema({
  name: { type: String },
  items: [
    {
      imgae: { type: String }, //广告位显示的图片
      url: { type: String } //点击广告位跳转的链接
    }
  ]
});

module.exports = mongoose.model("Ad", schema);
