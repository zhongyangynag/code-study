const mongoose = require("mongoose");
const Schema = mongoose.Schema;

const schema = new Schema({
  username: { type: String },
  password: {
    type: String,
    select: false, //默认是不能查出密码的
    set(val) {
      //密码的散列排布
      return require("bcrypt").hashSync(val, 10);
    }
  }
});

module.exports = mongoose.model("AdminUser", schema);
