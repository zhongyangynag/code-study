<!-- 创建管理员 -->
<template>
  <div>
    <h1>{{id?"编辑":"新建"}}管理员</h1>
    <el-form label-width="120px" @submit.native.prevent="save">
      <el-form-item label="用户名">
        <el-input v-model="model.username"></el-input>
      </el-form-item>
      <el-form-item label="密码">
        <el-input type="password" v-model="model.password"></el-input>
      </el-form-item>
      <el-form-item>
        <el-button type="primary" native-type="submit">保存</el-button>
        <el-button @click="$router.push('/admin_users/list')">取消</el-button>
      </el-form-item>
    </el-form>
  </div>
</template>

<script>
export default {
  props: ["id"],
  data() {
    return {
      model: {
        username: "",
        password: ""
      }
    };
  },
  methods: {
    async save() {
      this.model.username = this.model.username.trim();
      if (!this.model.username || !this.model.username.trim()) {
        this.$message({
          type: "error",
          showClose: true,
          message: "请输入账户名"
        });
        return;
      }

      let res = null;
      if (this.id) {
        res = await this.$http.put(`rest/admin_users/${this.id}`, this.model);
      } else {
        res = await this.$http.post("rest/admin_users", this.model);
      }
      this.$router.push("/admin_users/list");
      this.$message({
        type: "success",
        showClose: true,
        message: "保存成功"
      });
    },
    async fetch() {
      const res = await this.$http.get(`rest/admin_users/${this.id}`);
      this.model = res.data;
    }
  },
  created() {
    this.id && this.fetch(); //有id才请求
  }
};
</script>
<style>
</style>