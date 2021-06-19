
// 1、类的定义------------------------------------------------------------
class Person2 {
    name: string; // 属性 前面省略了public关键字
    constructor(n: string) { // 构造函数  实例化的时候触发的方法
        this.name = n;
    }
    run(): void {
        alert(this.name)
    }
    getName(): string {
        return this.name;
    }// 存取器getter setter
    setName(name: string) {
        this.name = name;
    }
    dowork(): string {
        return `${this.name}在运动`
    }
}
var p2 = new Person2('张三')
p2.run()// 输出张三
alert(p2.getName()) // 输出张三
p2.setName('李四');
alert(p2.getName()) // 输出李四

// 2、类的继承 extends super------------------------------------------------------------

class Web2 extends Person2 {
    constructor(name: string) {
        super(name);//初始化父类的构造函数 
    }
}

var w2 = new Web2('王武');
w2.run(); // 输出王武

// 2.1 ts中继承的探讨  父类的方法和子类的方法一致

class Web3 extends Person2 {
    constructor(name: string) {
        super(name);//初始化父类的构造函数 
    }
    dowork(): string {
        return `${this.name}在运动-子类`// this.name 获取父类的name
    }
    add(): string {
        return `${this.name}在算加法`
    }
}

var w3 = new Web3('王武');
w3.dowork(); // 输出王武在运动-子类
w3.add(); // 输出王武在算加法

// 3、类里面的修饰符  typescript里面定义属性的时候给我们提供类 三种修饰符  记录一个额外的readonly------------------------------------------------------------

// public : 公有       在当前类里面、子类、类外面都可以访问
// protected: 保护类型  在当前类里面、子类可以访问，类外部没法访问
// private: 私有        在当前类里面可以访问，子类、类外部没法访问
// 属性如果不加修饰符 默认就是公有public

class Person3 {
    private name: string;  /*私有*/
    protected name2: string; // 保护类型
    constructor(name: string) {
        this.name = name;
        this.name2 = name;
    }
    run(): string {
        return `${this.name}在运动`
    }
    work() {
        console.log(`${this.name2}在工作`)
    }
}

class Web4 extends Person3 {
    constructor(name2: string, name: string) {
        super(name2);//初始化父类的构造函数 
        // super(name2,name);//报错 name是私有子类不能用
    }
    add(): string {
        return `${this.name2}在算加法`
    }
}
var p3 = new Person3('哈哈哈');

alert(p3.run());// 报错 name是私有外部不能用

// readonly :只读属性关键字，只允许出现在属性声明或索引签名或构造函数中
class Animal {
    readonly name;
    public constructor(name) {
        this.name = name;
    }
}
let a = new Animal('Jack');
console.log(a.name); // Jack
// a.name = 'Tom'; // 报错 index.ts(10,3): TS2540: Cannot assign to 'name' because it is a read-only property.
// 注意如果 readonly 和其他访问修饰符同时存在的话，需要写在其后面。
class Animal3 {
    // public readonly name;
    public constructor(public readonly name) {
      // this.name = name;
    }
  }
// 4、静态属性 静态方法  ------------------------------------------------------------
//es5
function Person4() { }
Person4.age = 23;//静态属性
Person4.run2 = function () {
}// 静态方法
Person4.run2();// 静态方法的调用
//ts
class Per {
    name: string;
    age: number = 20;
    static sex = '男';// 静态属性
    constructor(name: string) {
        this.name = name;
    }
    run() {
        alert(`${this.name}在跑步`)
    }
    work() {
        alert(`${this.name}在工作,他${this.age}岁`)
    }
    static print() {// 静态方法，它里面没法直接调用类里面的属性
        alert(`print方法` + Per.sex)
    }
}
Per.print();// print方法男
alert(Per.sex);//男
// 现实中的例子，jquery里面就用到了

// 5、多态: 父类定义一个方法不去实现，让继承它的子类去实现，每一个子类都有不同的表现，多态属于继承------------------------------------------------------------

class Animal1 {
    name: string;
    constructor(name: string) {
        this.name = name;
    }
    eat() {//具体吃什么不知道，具体吃什么?继承它的子类去实现，每一个子类的表现不一样
        console.log('吃的方法')
    }
}
class Dog1 extends Animal1 {
    constructor(name: string) {
        super(name)
    }
    eat() {
        return this.name + '吃骨头'
    }
}
class Cat1 extends Animal1 {
    constructor(name: string) {
        super(name)
    }
    eat() {
        return this.name + '吃老鼠'
    }
}

// typescript中的抽象类：它是提供其他类继承的基类，不能直接被实例化。

// 用abstract关键字定义抽象类和抽象方法，抽象类中的抽象方法不包含具体实现并且必须在派生类中实现。

// abstract抽象方法只能放在抽象类里面 

// 抽象类和抽象方法用来定义标准。 标准：Animal 这个类要求它的子类必须包含eat方法

abstract class Animal2 {
    name: string;
    constructor(name: string) {
        this.name = name;
    }
    abstract eat(): any;
    run() {
        console.log('其他方法可以不实现')
    }
}
// var a=new Animal() /*错误的写法*/
class Dog2 extends Animal2 {
    constructor(name: any) {
        super(name)
    }
    eat() {//抽象类的子类必须实现抽象类里面的抽象方法
        console.log(this.name + '吃粮食')
    }
}
var d = new Dog2('小花花');
d.eat();