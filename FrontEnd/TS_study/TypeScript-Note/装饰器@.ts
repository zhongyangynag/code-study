// 1、装饰器介绍 // 2、装饰器定义
/*
    装饰器:装饰器是一种特殊类型的声明，它能够被附加到类声明，方法，属性或参数上，可以修改类的行为。
    通俗的讲装饰器就是一个方法，可以注入到类、方法、属性参数上来扩展类、属性、方法、参数的功能。
    常见的装饰器有：类装饰器、属性装饰器、方法装饰器、参数装饰器
    装饰器的写法：普通装饰器(无法传参)、 装饰器工厂（可传参）
    装饰器是过去几年中js最大的成就之一，已是Es7的标准特性之一

    写在谁前面，就装饰谁
*/
// 3、类装饰器 
// 3.1 普通装饰器（无法传参）
function logClass(params: any) {
    console.log(params);
    // params 就是当前类
    params.prototype.apiUrl = '动态扩展的属性';
    params.prototype.run = function () {
        console.log('我是一个run方法');
    }
}
@logClass
class HttpClient1 {
    constructor() { }
    getData() { }
}
var http: any = new HttpClient1();
console.log(http.apiUrl);
http.run();
// 3.2 装饰器工厂 可传参 return
function logClass1(params: string) {// params 传入过来的参数
    return function (target: any) { //target 传入过来的类
        console.log(target);
        console.log(params);
        target.prototype.apiUrl = params;
    }
}
@logClass1('http://www.itying.com/api')
class HttpClient2 {
    constructor() { }
    getData() { }
}
var http: any = new HttpClient2();
console.log(http.apiUrl);
// 3.3、类装饰器 重载构造函数
// 下面是一个重载构造函数的例子。
// 类装饰器表达式会在运行时当作函数被调用，类的构造函数作为其唯一的参数。
// 如果类装饰器返回一个值，它会使用提供的构造函数来替换类的声明。
function logClass3(target: any) {
    console.log(target);
    return class extends target {
        apiUrl: any = '我是修改后的数据';
        getData() { // 由于继承 就重载父亲的getData的实现
            this.apiUrl = this.apiUrl + '----';
            console.log(this.apiUrl);
        }
    }
}
@logClass3
class HttpClient3 {
    public apiUrl: string | undefined;
    constructor() {
        this.apiUrl = '我是构造函数里面的apiUrl';
    }
    getData() {
        console.log(this.apiUrl);
    }
}

var http3 = new HttpClient3();
http3.getData();//我是修改后的数据

// 5、属性装饰器
// 属性装饰器表达式会在运行时当作函数被调用，传入下列2个参数：
// (1)对于静态成员来说是类的构造函数，对于实例成员是类的原型对象。
// (2)成员的名字。
function logProperty(params: any) {
    return function (target: any, attr: any) {// target类的原型对象 attr属性名称
        console.log(target);// constructor() { }getData() {}
        console.log(attr);// url
        target[attr] = params;
    }
}
@logClass1('xxxx')
class HttpClient4 {
    @logProperty('http://baidu.com')// 注意装饰器不需要加;号
    public url: any | undefined;
    constructor() { }
    getData() {
        console.log(this.url);
    }
}
var http4 = new HttpClient4();
http4.getData();// http://baidu.com


// 6、方法装饰器
// 它会被应用到方法的 属性描述符上，可以用来监视，修改或者替换方法定义。
// 方法装饰会在运行时传入下列3个参数：
//     1、对于静态成员来说是类的构造函数，对于实例成员是类的原型对象。
//     2、成员的名字。
//     3、成员的属性描述符。

function get(params: any) {
    return function (target: any, methodName: any, desc: any) {
        console.log(target);
        console.log(methodName);// getData
        console.log(desc);// desc.value 是getData这个方法
        target.apiUrl = 'xxxx';
        target.run = function () {
            console.log('run');
        }
        //修改装饰器的方法  把装饰器方法里面传入的所有参数改为string类型
        //1、保存当前的方法
        var oMethod = desc.value;
        desc.value = function (...args: any[]) {
            args = args.map((value) => {
                return String(value);
            })
            oMethod.apply(this, args);
        }
    }
}

class HttpClient5 {
    public url: any | undefined;
    constructor() {
    }
    @get('http://www.itying,com')
    getData(...args: any[]) {
        console.log(args);
        console.log('我是getData里面的方法');
    }
}

var http5: any = new HttpClient5();
console.log(http5.apiUrl);
http5.run();
http5.getData(123, 'xxx');


// 7、方法参数装饰器
// 参数装饰器表达式会在运行时当作函数被调用，可以使用参数装饰器为类的原型增加一些元素数据 ，传入下列3个参数：
// 1、对于静态成员来说是类的构造函数，对于实例成员是类的原型对象。
// 2、方法的名字。
// 3、参数在函数参数列表中的索引。
function logParams(params: any) {
    return function (target: any, methodName: any, paramsIndex: any) {
        console.log(params);// xxxxx
        console.log(target);// 类的原型对象
        console.log(methodName);// getData
        console.log(paramsIndex);//0
        target.apiUrl = params;
    }
}

class HttpClient6 {
    public url: any | undefined;
    constructor() {
    }
    getData(@logParams('xxxxx') uuid: any) {
        console.log(uuid);
    }
}


var http6: any = new HttpClient6();
http6.getData(123456);//123456
console.log(http6.apiUrl);// xxxxx


// 8、装饰器执行顺序
// (1)参数装饰器，然后依次是方法装饰器，访问符装饰器，或属性装饰器应用到每个实例成员。
// (2)参数装饰器，然后依次是方法装饰器，访问符装饰器，或属性装饰器应用到每个静态成员。
// (3)参数装饰器应用到构造函数。
// (4)类装饰器应用到类。

//属性》方法》方法参数》类
// 如果有多个同样的装饰器，它会先执行后面的
function logClass9(params:string){
    return function(target:any){
      console.log('类装饰器1')
    }
}

function logClass2(params:string){
    return function(target:any){
      console.log('类装饰器2')
    }
}

function logAttribute1(params?:string){
    return function(target:any,attrName:any){
      console.log('属性装饰器1')
    }
}

function logAttribute2(params?:string){
    return function(target:any,attrName:any){
      console.log('属性装饰器2')
    }
}

function logMethod1(params?:string){
    return function(target:any,attrName:any,desc:any){
      console.log('方法装饰器1')
    }
}
function logMethod2(params?:string){
    return function(target:any,attrName:any,desc:any){
      console.log('方法装饰器2')
    }
}



function logParams1(params?:string){
    return function(target:any,attrName:any,desc:any){
      console.log('方法参数装饰器1')
    }
}

function logParams2(params?:string){
    return function(target:any,attrName:any,desc:any){
      console.log('方法参数装饰器2')
    }
}

@logClass9('http://www.itying.com/api')
@logClass2('xxxx')
class HttpClient{
    @logAttribute1()
    @logAttribute2()
    public apiUrl:string | undefined;
    constructor(){
    }

    @logMethod1()
    @logMethod2()
    getData(){
        return true;
    }

    setData(@logParams1() attr1:any,@logParams2() attr2:any,){

    }
}

var http:any=new HttpClient();

// 9、装饰器扩展-访问器装饰器
// 对于静态成员来说是类的构造函数，对于实例成员是类的原型对象。
// 成员的名字。
// 成员的属性描述符。
function configurable(value: boolean) {
    return function (target: any, propertyKey: string, descriptor: PropertyDescriptor) {
        descriptor.configurable = value;
    };
}
class Point {
    private _x: number;
    private _y: number;
    constructor(x: number, y: number) {
        this._x = x;
        this._y = y;
    }

    @configurable(false)
    get x() { return this._x; }

    @configurable(false)
    get y() { return this._y; }
}