const mongoose = require("mongoose");
const Schema = mongoose.Schema;

const schema = new Schema({
  name: { type: String },
  icon: { type: String } //我们不会将一整张图片保存到数据库中,而是保存一个图片地址,通过数据库获取这个地址
});

module.exports = mongoose.model("Item", schema);
