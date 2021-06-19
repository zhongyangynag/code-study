
import {MysqlDb6} from './encapsulationDb';

//定义数据库的映射
class ArticleClass{
    title:string | undefined;
    desc:string | undefined;
}


var ArticleModel=new MysqlDb6<ArticleClass>();
export {
    ArticleClass,ArticleModel
}





