
/*
接口的作用：在面向对象的编程中，接口是一种规范的定义，它定义了行为和动作的规范，在程序设计里面，
接口起到一种限制和规范的作用。接口定义了某一批类所需要遵守的规范，接口不关心这些类的内部状态数据，
也不关心这些类里方法的实现细节，它只规定这批类里必须提供某些方法，提供这些方法的类就可以满足实际需要。
typescrip中的接口类似于java，同时还增加了更灵活的接口类型，包括属性、函数、可索引和类等。

定义标准。
*/

// 1、属性接口,可选属性 -- 对json的约束--------------------
interface FullName {
    firstName: string;
    secondName: string;
    thiredName?: string;// 可选属性
}
function printName(obj: FullName) {
    console.log(obj.firstName + '--' + obj.secondName);
}
// printName('1213');  //错误
var obj = {   /*传入的参数必须包含 firstName  secondName 参数的顺序可以不一样*/
    age: 20,
    firstName: '张',
    secondName: '三'
};
printName(obj)

// 实例
interface Config {
    type: string;
    url: string;
    data?: string;
    dataType: string;
}

//原生js封装的ajax 
function ajax(config: Config) {

    var xhr = new XMLHttpRequest();

    xhr.open(config.type, config.url, true);

    xhr.send(config.data);

    xhr.onreadystatechange = function () {

        if (xhr.readyState == 4 && xhr.status == 200) {
            console.log('chengong');


            if (config.dataType == 'json') {

                console.log(JSON.parse(xhr.responseText));
            } else {
                console.log(xhr.responseText)

            }


        }
    }
}

ajax({
    type: 'get',
    data: 'name=zhangsan',
    url: 'http://a.itying.com/api/productlist', //api
    dataType: 'json'
})

// 2、函数类型接口: 对方法传入的参数 以及返回值进行约束    批量约束--------------------

// 加密的函数类型接口
interface encrypt {
    (key: string, value: string): string;
}
var md5: encrypt = function (key: string, value: string): string {
    //模拟操作
    return key + value;
}
console.log(md5('name', 'zhangsan'));

// 3、 可索引接口：数组、对象的约束  （不常用）-----------------
var arr: number[] = [1, 2, 3];
var arr1: Array<string> = ['123', '223'];
//可索引接口 对数组的约束
interface UserArr {
    [index: number]: string
}
var arr2: UserArr = ['aaa', 'bbb'];
console.log(arr2[0]);
//可索引接口 对对象的约束
interface UserObj {
    [index: string]: string
}
var arr3: UserObj = { name: '张三' };


// 4、类类型接口:对类的约束  和   抽象类抽象有点相似 implements: 实现某一个接口------------
// 有属性约束，有方法约束就是类类型接口
interface Animal4 {
    name: string;
    eat(str: string): void;
}
class Dog implements Animal4 {
    name: string;
    constructor(parameters: string) {
        this.name = parameters;
    }
    eat() {
        console.log(this.name + '吃粮食')
    }
}
var d = new Dog('小黑');
d.eat();
// 父定一个标准，子必须实现定义的方法。

// 5、接口扩展 -------------
//接口扩展：接口可以继承接口   
interface Animal {
    eat(): void;
}
interface Person extends Animal {
    work(): void;
}
class Programmer {
    public name: string;
    constructor(name: string) {
        this.name = name;
    }
    coding(code: string) {
        console.log(this.name + code)
    }
}
class Web extends Programmer implements Person {
    constructor(name: string) {
        super(name)
    }
    eat() {
        console.log(this.name + '喜欢吃馒头')
    }
    work() {
        console.log(this.name + '写代码');
    }
}

var w = new Web('小李');
w.eat();
w.coding('写ts代码');

