const mongoose = require("mongoose");
const Schema = mongoose.Schema;

const schema = new Schema({
  title: { type: String },
  categories: [
    {
      type: mongoose.SchemaTypes.ObjectId,
      ref: "Category"
    }
  ],
  body: {
    type: String
  }
});

module.exports = mongoose.model("Article", schema);
