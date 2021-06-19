<!-- 创建英雄 -->
<template>
  <div>
    <h1>{{id?"编辑":"新建"}}英雄</h1>
    <el-form label-width="120px" @submit.native.prevent="save">
      <el-tabs type="border-card" value="basic">
        <el-tab-pane label="基础信息" name="basic">
          <el-form-item label="名称">
            <el-input v-model="model.name"></el-input>
          </el-form-item>
          <el-form-item label="头像">
            <!-- el-upload就是elment-ui中专门用于处理上传文件的组件 -->
            <el-upload
              class="avatar-uploader"
              :action="uploadUrl"
              :headers="getAuthHeaders()"
              :show-file-list="false"
              :on-success="afterUpload"
            >
              <img v-if="model.avater" :src="model.avater" class="avatar" />
              <i v-else class="el-icon-plus avatar-uploader-icon"></i>
            </el-upload>
          </el-form-item>
          <el-form-item label="称号">
            <el-input v-model="model.title"></el-input>
          </el-form-item>
          <el-form-item label="类型">
            <el-select v-model="model.categories" multiple>
              <!--multiple为可以多选-->
              <el-option
                v-for="item in categories"
                :key="item._id"
                :label="item.name"
                :value="item._id"
              ></el-option>
            </el-select>
          </el-form-item>
          <!-- 评分 -->
          <el-form-item label="难度">
            <!-- 多层级的对象请求可能报错,所以需要用事先定义该属性 -->
            <!-- el-rate为一个评分组合 -->
            <el-rate
              style="margin-top:0.6rem"
              :max="10"
              show-score
              v-model="model.scores.difficult"
            ></el-rate>
          </el-form-item>
          <el-form-item label="技能">
            <!-- 多层级的对象请求可能报错,所以需要用事先定义该属性 -->
            <!-- el-rate为一个评分组合 -->
            <el-rate style="margin-top:0.6rem" :max="10" show-score v-model="model.scores.skills"></el-rate>
          </el-form-item>
          <el-form-item label="攻击">
            <!-- 多层级的对象请求可能报错,所以需要用事先定义该属性 -->
            <!-- el-rate为一个评分组合 -->
            <el-rate style="margin-top:0.6rem" :max="10" show-score v-model="model.scores.attack"></el-rate>
          </el-form-item>
          <el-form-item label="生存">
            <!-- 多层级的对象请求可能报错,所以需要用事先定义该属性 -->
            <!-- el-rate为一个评分组合 -->
            <el-rate style="margin-top:0.6rem" :max="10" show-score v-model="model.scores.survive"></el-rate>
          </el-form-item>
          <!-- 出装 -->
          <el-form-item label="顺风出装">
            <el-select v-model="model.item1" multiple>
              <!--multiple为可以多选-->
              <el-option v-for="item in items" :key="item._id" :label="item.name" :value="item._id"></el-option>
            </el-select>
          </el-form-item>
          <el-form-item label="逆风出装">
            <el-select v-model="model.item2" multiple>
              <!--multiple为可以多选-->
              <el-option v-for="item in items" :key="item._id" :label="item.name" :value="item._id"></el-option>
            </el-select>
          </el-form-item>

          <el-form-item label="使用技巧">
            <el-input type="textarea" v-model="model.usageTips"></el-input>
          </el-form-item>
          <el-form-item label="对抗技巧">
            <el-input type="textarea" v-model="model.battleTips"></el-input>
          </el-form-item>
          <el-form-item label="团战思路">
            <el-input type="textarea" v-model="model.temTips"></el-input>
          </el-form-item>
        </el-tab-pane>

        <el-tab-pane label="技能" name="skills">
          <el-button @click="model.skills.push({})" size="small">
            <i class="el-icon-plus"></i>添加技能
          </el-button>
          <el-row type="flex" style="flex-wrap:wrap">
            <el-col :md="12" v-for="(item,index) in model.skills" :key="index">
              <el-form-item label="名称">
                <el-input v-model="item.name"></el-input>
              </el-form-item>

              <el-form-item label="图标">
                <!-- on-success需要改变,因为是复制到每个技能的icon属性上,并且由于是增加一个新的属性,是需要使用$set来进行设置 -->
                <el-upload
                  class="avatar-uploader"
                  :action="uploadUrl"
                  :headers="getAuthHeaders()"
                  :show-file-list="false"
                  :on-success="res => $set(item,'icon',res.url)"
                >
                  <img v-if="item.icon" :src="item.icon" class="avatar" />
                  <i v-else class="el-icon-plus avatar-uploader-icon"></i>
                </el-upload>
              </el-form-item>

              <el-form-item label="描述">
                <el-input type="textarea" v-model="item.description"></el-input>
              </el-form-item>

              <el-form-item label="小提示">
                <el-input type="textarea" v-model="item.tips"></el-input>
              </el-form-item>
              <el-form-item>
                <el-button size="small" type="danger" @click="removeSkill(index)">删除</el-button>
              </el-form-item>
            </el-col>
          </el-row>
        </el-tab-pane>
      </el-tabs>

      <el-form-item style="margin-top:1rem">
        <el-button type="primary" native-type="submit">保存</el-button>
        <el-button @click="$router.push('/heroes/list')">取消</el-button>
      </el-form-item>
    </el-form>
  </div>
</template>

<script>
export default {
  props: ["id"],
  data() {
    return {
      //英雄的分类
      categories: [],
      //物品
      items: [],
      model: {
        name: "",
        avater: "",
        title: "",
        scores: {
          difficult: 0
        },
        usageTips: "",
        skills: []
      }
    };
  },
  methods: {
    async save() {
      this.model.name = this.model.name.trim();
      if (!this.model.name) {
        this.$message({
          type: "error",
          showClose: true,
          message: "请输入英雄名称"
        });
        return;
      }

      let res = null;
      if (this.id) {
        res = await this.$http.put(`rest/heroes/${this.id}`, this.model);
      } else {
        res = await this.$http.post("rest/heroes", this.model);
      }
      this.$router.push("/heroes/list");
      this.$message({
        type: "success",
        showClose: true,
        message: "保存成功"
      });
    },
    removeSkill(index) {
      this.$confirm(`是否确定删除该技能吗(如果不保存也不会删除)?`, "提示", {
        confirmButtonText: "确定",
        cancelButtonText: "取消",
        type: "warning"
      }).then(() => {
        this.model.skills.splice(index, 1);
      });
    },
    async fetch() {
      const res = await this.$http.get(`rest/heroes/${this.id}`);
      // 最好不使用直接覆盖掉原来对象的方法,而是使用对象合并的方法,避免报错
      this.model = Object.assign({}, this.model, res.data);
    },
    async fetchCategories() {
      const res = await this.$http.get(`rest/categories`);
      this.categories = res.data;
    },
    async fetchItems() {
      const res = await this.$http.get(`rest/items`);
      this.items = res.data;
    },
    afterUpload(res) {
      //请求完成后将请求的返回值进行赋值,该函数是在上传的时候自动调用请求
      this.model.avater = res.url;
    }
  },
  created() {
    this.fetchItems();
    this.fetchCategories();
    this.id && this.fetch(); //有id才请求
  }
};
</script>
<style>
.avatar-uploader .el-upload {
  border: 1px dashed #d9d9d9;
  border-radius: 6px;
  cursor: pointer;
  position: relative;
  overflow: hidden;
}
.avatar-uploader .el-upload:hover {
  border-color: #409eff;
}
.avatar-uploader-icon {
  font-size: 28px;
  color: #8c939d;
  width: 5rem;
  height: 5rem;
  line-height: 5rem;
  text-align: center;
}
.avatar {
  width: 5rem;
  height: 5rem;
  display: block;
}
</style>