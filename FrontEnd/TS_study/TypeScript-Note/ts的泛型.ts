// 1、泛型的定义-----------------------

// 泛型：软件工程中，我们不仅要创建一致的定义良好的API，同时也要考虑可重用性。 组件不仅能够支持当前的数据类型，同时也能支持未来的数据类型，这在创建大型系统时为你提供了十分灵活的功能。
// 在像C#和Java这样的语言中，可以使用泛型来创建可重用的组件，一个组件可以支持多种类型的数据。 这样用户就可以以自己的数据类型来使用组件。
// 通俗理解：泛型就是解决 类 接口 方法的复用性、以及对不特定数据类型的支持(类型校验)

// 2、泛型函数-------------------------

// 只能返回string类型的数据
// 同时返回 string类型 和number类型  （代码冗余） any可以解决这个问题
function getData1(value: string): string {
    return `${value}hahah`
}
function getData2(value: number): number {
    return value + 10
}
function getData3(value: any): any {
    return value + 10
}// any放弃了类型检查,传入什么 返回什么。传入的参数类型和返回的参数类型可以不一致。不能实现:传入number 类型必须返回number类型  传入string类型必须返回string类型 泛型可以

// 泛型：可以支持不特定的数据类型   要求：传入的参数和返回的参数一致
// T表示泛型，具体什么类型是调用这个方法的时候决定的
function getData4<T>(value: T): T {
    // return 'value'; // 报错
    return value;
}
getData4<number>(123);
getData4<string>('1214231');
// getData4<number>('2112');       /*错误的写法*/

function getData5<T>(value: T): any { // 返回什么都行
    return '2145214214';
}
getData5<number>(123);  //参数必须是number
getData5<string>('这是一个泛型');  //参数必须是string

// 3、泛型类：比如有个最小堆算法，需要同时支持返回数字和字符串 a  -  z两种类型。  通过类的泛型来实现--------------------------------------
class MinClass<T> {
    public list: T[] = [];
    add(value: T): void {
        this.list.push(value)
    }
    min(): T {
        var min = this.list[0];
        for (var i = 0; i < this.list.length; i++) {
            if (min > this.list[i]) {
                min = this.list[i]
            }
        }
        return min;
    }
}
var m1 = new MinClass<number>();   /*实例化类 并且制定了类的T代表的类型是number*/
m1.add(11);
m1.add(3);
m1.add(2);
alert(m1.min())

var m2 = new MinClass<string>();   /*实例化类 并且制定了类的T代表的类型是string*/
m2.add('c');
m2.add('a');
m2.add('v');
alert(m2.min())

// 4、泛型接口-------------------------------------------
// 第一种方法
interface ConfigFn {
    <T>(value: T): T
}
var getData6: ConfigFn = function <T>(value: T): T {
    return value;
}
getData6<string>('张三');
// getData6<string>(1243);  //错误

// 第二种方法
interface ConfigFn2<T> {
    (value: T): T;
}
function getData7<T>(value: T): T {
    return value
}
var myGetdata: ConfigFn2<string> = getData7;
myGetdata('20');
// myGetData(20)  //错误

// 5、把类作为参数类型的泛型类----------------------

// 定义一个User的类这个类的作用就是映射数据库字段  
// 然后定义一个 MysqlDb的类这个类用于操作数据库   
// 然后把User类作为参数传入到MysqlDb中

//把类作为参数来约束数据传入的类型 
class User {
    username: string | undefined;
    pasword: string | undefined;
}
class MysqlDb {
    add(user: User): boolean {
        console.log(user);
        return true;
    }
}
var u = new User();
u.username = '张三';
u.pasword = '123456';
var Db = new MysqlDb();
Db.add(u);

//定义操作数据库的泛型类
class MysqlDb2<T> {
    add(info: T): boolean {
        console.log(info)
        return true
    }
    updated(info: T, id: number): boolean {
        console.log(info, id)
        return true
    }
}
//想给User表增加数据

// 5.1、定义一个User类 和数据库进行映射
class User2{
    username:string | undefined;
    pasword:string | undefined;
}
var u=new User2();
u.username='张三';
u.pasword='123456';
var Db2=new MysqlDb2<User>();
Db2.add(u);

//5.2、相关ArticleCate增加数据  定义一个ArticleCate类 和数据库进行映射
class ArticleCate2{
    title:string | undefined;
    desc:string | undefined;
    status:number | undefined;
    constructor(params:{
        title:string | undefined,
        desc:string | undefined,
        status?:number | undefined
    }){

        this.title=params.title;
        this.desc=params.desc;
        this.status=params.status;
    }
}
//增加操作
var a1=new ArticleCate2({
    title:'分类',
    desc:'1111',
    status:1
});

// //类当做参数的泛型类
var Db4=new MysqlDb2<ArticleCate2>();
Db4.add(a1);

//修改数据
var a2=new ArticleCate2({
        title:'分类111',
        desc:'2222'      
});
a2.status=0;
var Db3=new MysqlDb2<ArticleCate2>();
Db3.updated(a2,12);

// 6、扩展----------------------------

// 多个类型参数
function swap<T,U>(tuple:[T,U]):[U,T]{//我们定义了一个 swap 函数，用来交换输入的元组。
    return [tuple[1],tuple[0]]
}
swap([7, 'seven']); // ['seven', 7]

// 泛型约束
interface Lengthwise {
    length: number;
}
// 我们使用了 extends 约束了泛型 T 必须符合接口 Lengthwise 的形状，也就是必须包含 length 属性。
function loggingIdentity<T extends Lengthwise>(arg: T): T {
    console.log(arg.length);// 约束参数必须有length属性
    return arg;
}

// 多个类型参数之间也可以互相约束
function copyFields<T extends U, U>(target: T, source: U): T {
    for (let id in source) {
        target[id] = (<T>source)[id];
    }
    return target;
}
// 我们使用了两个类型参数，其中要求 T 继承 U，这样就保证了 U 上不会出现 T 中不存在的字段。
// 子类都不存在的字段，父类肯定没有
let x = { a: 1, b: 2, c: 3, d: 4 };

copyFields(x, { b: 10, d: 20 });

