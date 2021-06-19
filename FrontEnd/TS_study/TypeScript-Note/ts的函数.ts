// 1、函数的定义
// ==函数声明法==
function run(): string {
    return 'run';
}
// ==匿名函数==
var fun2 = function (): number {
    return 123;
}

// 2、ts定义传参
// ==基本传参==
function getInfo1(name: string, age: number): string {
    return `${name}---${age}`;
}
var getInfo2 = function (name: string, age: number): string {
    return `${name}---${age}`;
}
// ==方法可选参数==
function getInfo3(name: string, age?: number): string {
    if (age) {
        return `${name} --- ${age}`;
    } else {
        return `${name} ---年龄保密`;
    }
}//注意:可选参数必须配置到必需参数的最后面

// ==默认参数，可选参数==
// es5里面没法设置默认参数，es6和ts中都可以设置默认参数
function getInfo4(name: string, age: number = 20): string {
    if (age) {
        return `${name} --- ${age}`;
    } else {
        return `${name} ---年龄保密`;
    }
}
// ==剩余参数==
// 三点运算符 接受新参传过来的值
function sum1(...result: number[]): number {
    var sum = 0;
    for (var i = 0; i < result.length; i++) {
        sum += result[i];
    }
    return sum;
}
alert(sum1(1, 2, 3, 4, 5, 6));

// 另一种写法
function sum2(a: number, b: number, ...result: number[]): number {
    var sum = a + b;
    for (var i = 0; i < result.length; i++) {
        sum += result[i];
    }
    return sum;
}
alert(sum2(1, 2, 3, 4, 5, 6));
// ==没有返回值==
function run2(): void {
    console.log('run')
}
run2();


// 3、ts函数重载
// java中方法的重载：重载指的是两个或者两个以上同名函数，但它们的参数不一样，这时会出现函数重载的情况。
// typescript中的重载：通过为同一个函数提供多个函数类型定义来实现多种功能的目的。
// ts为了兼容es5 以及 es6 重载的写法和java中有区别。

//es5中出现同名方法，下面的会替换上面的方法
// function css(config) { }
// function css(config, value) { }

//ts中的重载
// TypeScript 会优先从最前面的函数定义开始匹配，所以多个函数定义如果有包含关系，需要优先把精确的定义写在前面。

// function getInfo(name:string):string;
// function getInfo(age:number):string;
// function getInfo(str:any):any{
// if(typeof str==='string'){
// return '我叫：'+str;
// }else{
// return '我的年龄是'+str;
// }
// }
// alert(getInfo('张三')); //正确
// alert(getInfo(20)); //正确
// alert(getInfo(true)); //错误写法

// 第二种
function getInfo(name: string): string;
function getInfo(name: string, age: number): string;
function getInfo(name: any, age?: any): any {
    if (age) {
        return '我叫：' + name + '我的年龄是' + age;
    } else {
        return '我叫：' + name;
    }
}
// alert(getInfo('zhangsan')); /*正确*/
// alert(getInfo(123)); 错误
// alert(getInfo('zhangsan',20));  /*正确*/

// 4、箭头函数 es6
//this指向的问题 箭头函数里面的this指向上下文
setTimeout(() => {
    alert('run')
}, 1000)