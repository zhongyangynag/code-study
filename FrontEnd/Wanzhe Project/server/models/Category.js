const mongoose = require("mongoose");
const Schema = mongoose.Schema;

const schema = new Schema({
  name: { type: String },
  parents: {
    type: mongoose.SchemaTypes.ObjectId,
    ref: "Category"
  }
});

module.exports = mongoose.model("Category", schema);
