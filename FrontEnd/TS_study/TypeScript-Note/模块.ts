// 7.1 模块的的概念
/*
我的理解：模块/模块化：将公工的部分抽取出来，默认是私有的，就需要export import

模块的的概念（官方）:
         关于术语的一点说明: 请务必注意一点，TypeScript 1.5里术语名已经发生了变化。 “内部模块”现在称做“命名空间”。
         “外部模块”现在则简称为“模块” 模块在其自身的作用域里执行，而不是在全局作用域里；
         这意味着定义在一个模块里的变量，函数，类等等在模块外部是不可见的，除非你明确地使用export形式之一导出它们。 
         相反，如果想使用其它模块导出的变量，函数，类，接口等的时候，你必须要导入它们，可以使用 import形式之一。
模块的概念（自己理解）：
        我们可以把一些公共的功能单独抽离成一个文件作为一个模块。
        模块里面的变量 函数 类等默认是私有的，如果我们要在外部访问模块里面的数据（变量、函数、类），
        我们需要通过export暴露模块里面的数据（变量、函数、类...）。
        暴露后我们通过 import 引入模块就可以使用模块里面暴露的数据（变量、函数、类...）。
*/

// 7.2 模块导出的几种方法----------------------

// export 导出声明  
// export 导出语句
// export default
// import导入模块
import { getData, save } from './model/db';
getData();
save();
import { dbUrl, getData as get } from './model/db';
console.log(dbUrl);
get();

// 7.3 模块化封装上一讲的DB库-----------------

//操作用户表   定义一个User类和数据表做映射
import { MysqlDb6 } from './model/encapsulationDb'
class User {
    username: string | undefined;
    password: string | undefined;
}
var u = new User();
u.username = '张三2222';
u.password = '123456';
var oMssql = new MysqlDb6<User>();
oMssql.add(u);

// 自定义
import {UserClass,UserModel} from './model/user';
import {ArticleClass,ArticleModel} from './model/article';

//增加数据
var u=new UserClass();
u.username='张三';
u.password='12345655654757';
UserModel.add(u);

//获取user表数据
var res=UserModel.get(123);
console.log(res);

//获取文章表的数据
var aRes=ArticleModel.get(1);
console.log(aRes);

