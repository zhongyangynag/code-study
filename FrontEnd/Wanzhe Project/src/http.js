import Vue from "vue";
import router from "./router/index";
import axios from "axios";

const http = axios.create({
  baseURL: "http://localhost:3000/admin/api"
});

//一个拦截器,对所有请求的接口添加请求头,后台要进行对请求头的判断
http.interceptors.request.use(
  config => {
    //可以不在前面加Bearer,但是由于接口不只有一种类型,所以遵循行业规范
    if (localStorage.token) {
      config.headers.Authorization = "Bearer " + localStorage.token;
    }
    return config;
  },
  err => {
    return Promise.reject(err);
  }
);

//一个拦截器,当后台的返回状态为400以上是进入err,200进入res
http.interceptors.response.use(
  res => {
    return res;
  },
  err => {
    ///err.presponse.data.message是后端传过来的值
    if (err.response.data.message) {
      Vue.prototype.$message({
        type: "error",
        message: err.response.data.message
      });
    }

    if (err.response.status === 401) {
      router.push("/login");
    }
    return Promise.reject(err);
  }
);

export default http;
