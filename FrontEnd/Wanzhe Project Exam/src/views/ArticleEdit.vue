<!-- 创建文章 -->
<template>
  <div>
    <h1>{{id?"编辑":"新建"}}文章</h1>
    <el-form label-width="120px" @submit.native.prevent="save">
      <el-form-item label="所属分类">
        <el-select v-model="model.categories" multiple>
          <el-option
            v-for="item in categories"
            :key="item._id"
            :label="item.name"
            :value="item._id"
          ></el-option>
        </el-select>
      </el-form-item>
      <el-form-item label="标题">
        <el-input v-model="model.title"></el-input>
      </el-form-item>
      <el-form-item label="详情">
        <!-- 设置图片上传的时候需要自定义,不然数据量太大了 -->
        <vue-editor useCustomImageHandler @imageAdded="handleImageAdded" v-model="model.body"></vue-editor>
      </el-form-item>
      <el-form-item>
        <el-button type="primary" native-type="submit">保存</el-button>
        <el-button @click="$router.push('/articles/list')">取消</el-button>
      </el-form-item>
    </el-form>
  </div>
</template>

<script>
import { VueEditor } from "vue2-editor";

export default {
  props: ["id"],
  data() {
    return {
      model: {
        categories: [],
        title: "",
        body: ""
      },
      categories: []
    };
  },
  components: {
    VueEditor
  },
  methods: {
    async handleImageAdded(file, Editor, cursorLocation, resetUploader) {
      const formData = new FormData();
      //改名为file是为了和后端对接
      formData.append("file", file);

      const res = await this.$http.post("upload", formData);
      Editor.insertEmbed(cursorLocation, "image", res.data.url); //这里的url也是后端传过来的
      resetUploader();
    },
    async save() {
      this.model.title = this.model.title.trim();
      if (!this.model.title) {
        this.$message({
          type: "error",
          showClose: true,
          message: "请输入文章标题"
        });
        return;
      } else if (!this.model.categories.length) {
        this.$message({
          type: "error",
          showClose: true,
          message: "请选择文章分类"
        });
        return;
      }

      let res = null;
      if (this.id) {
        res = await this.$http.put(`rest/articles/${this.id}`, this.model);
      } else {
        res = await this.$http.post("rest/articles", this.model);
      }
      this.$router.push("/articles/list");
      this.$message({
        type: "success",
        showClose: true,
        message: "保存成功"
      });
    },
    async fetch() {
      const res = await this.$http.get(`rest/articles/${this.id}`);
      this.model = res.data;
    },
    async fetchCategories() {
      const res = await this.$http.get("rest/categories");
      this.categories = res.data;
    }
  },
  created() {
    this.fetchCategories();
    this.id && this.fetch(); //有id才请求
  }
};
</script>
<style>
</style>