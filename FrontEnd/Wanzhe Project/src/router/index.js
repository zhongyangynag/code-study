import Vue from "vue";
import Router from "vue-router";
//登录路由
import Login from "../views/Login.vue";

//主路由
import Main from "../views/Main.vue";
//分类路由
import CategoryEdit from "../views/CategoryEdit.vue";
import CategoryList from "../views/CategoryList.vue";
//物品路由
import ItemEdit from "../views/ItemEdit.vue";
import ItemList from "../views/ItemList.vue";
//英雄路由
import HeroEdit from "../views/HeroEdit.vue";
import HeroList from "../views/HeroList.vue";
//文章路由
import ArticleEdit from "../views/ArticleEdit.vue";
import ArticleList from "../views/ArticleList.vue";
//广告位路由
import AdEdit from "../views/AdEdit.vue";
import AdList from "../views/AdList.vue";
//管理员路由
import AdminUserEdit from "../views/AdminUserEdit.vue";
import AdminUserList from "../views/AdminUserList.vue";

Vue.use(Router);

const router = new Router({
  routes: [
    // 加导航守卫,可以只给一个提供公共,也可以分别给要授权的路由提供授权,这里就只给登录页加了
    {
      path: "/login",
      name: "login",
      component: Login,
      meta: { isPublic: true }
    },
    {
      path: "/",
      name: "main",
      redirect: "/categories/list",
      component: Main,
      children: [
        // 分类路由
        { path: "/categories/create", component: CategoryEdit },
        { path: "/categories/edit/:id", component: CategoryEdit, props: true }, //props为true代表将传入的pararms中带的参数id都注入带props的id里面
        { path: "/categories/list", component: CategoryList },
        //物品路由
        { path: "/items/create", component: ItemEdit },
        { path: "/items/edit/:id", component: ItemEdit, props: true }, //props为true代表将传入的pararms中带的参数id都注入带props的id里面
        { path: "/items/list", component: ItemList },
        //英雄路由
        { path: "/heroes/create", component: HeroEdit },
        { path: "/heroes/edit/:id", component: HeroEdit, props: true }, //props为true代表将传入的pararms中带的参数id都注入带props的id里面
        { path: "/heroes/list", component: HeroList },
        //文字路由
        { path: "/articles/create", component: ArticleEdit },
        { path: "/articles/edit/:id", component: ArticleEdit, props: true }, //props为true代表将传入的pararms中带的参数id都注入带props的id里面
        { path: "/articles/list", component: ArticleList },
        //广告位路由
        { path: "/ads/create", component: AdEdit },
        { path: "/ads/edit/:id", component: AdEdit, props: true }, //props为true代表将传入的pararms中带的参数id都注入带props的id里面
        { path: "/ads/list", component: AdList },
        //管理员路由
        { path: "/admin_users/create", component: AdminUserEdit },
        {
          path: "/admin_users/edit/:id",
          component: AdminUserEdit,
          props: true
        }, //props为true代表将传入的pararms中带的参数id都注入带props的id里面
        { path: "/admin_users/list", component: AdminUserList }
      ]
    },
    {
      path: "*",
      name: "404",
      redirect: "/categories/list"
    }
  ]
});

router.beforeEach((to, from, next) => {
  if (!to.meta.isPublic && !localStorage.token) {
    return next("/login");
  }
  next();
});

export default router;
