import {MysqlDb6} from './encapsulationDb'
//定义数据库的映射
class UserClass{
    username:string | undefined;
    password:string | undefined;
}
var UserModel=new MysqlDb6<UserClass>();
export {
    UserClass,UserModel
}
