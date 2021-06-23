const mongoose = require("mongoose");
const Schema = mongoose.Schema;

const schema = new Schema({
  name: { type: String },
  avater: { type: String }, //我们不会将一整张图片保存到数据库中,而是保存一个图片地址,通过数据库获取这个地址
  title: { type: String }, //英雄称号
  categories: [{ type: mongoose.SchemaTypes.ObjectId, ref: "Category" }], //一个英雄关联多个分类
  scores: {
    //英雄评分
    difficult: { type: Number },
    skills: { type: Number },
    attack: { type: Number },
    survive: { type: Number }
  },
  //技能,有多个技能,一个技能有图片,名字,描述,小提示等
  skills: [
    {
      icon: { type: String },
      name: { type: String },
      description: { type: String },
      tips: { type: String }
    }
  ],
  //英雄推荐装备,顺风出装和逆风出装
  item1: [{ type: mongoose.SchemaTypes.ObjectId, ref: "Item" }],
  item2: [{ type: mongoose.SchemaTypes.ObjectId, ref: "Item" }],
  //使用技巧
  usageTips: { type: String },
  //对抗技巧
  battleTips: { type: String },
  //团战技巧
  temTips: { type: String },
  //搭档及其描述
  partners: [
    {
      hero: { type: mongoose.SchemaTypes.ObjectId, ref: "Hero" },
      description: { type: String }
    }
  ]
});

module.exports = mongoose.model("Hero", schema);
