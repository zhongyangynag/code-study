// 1、布尔类型（boolean）
var flag: boolean = true;
flag = false; //正确
// 2、数字类型（number）
var num: number = 123;
num = 456;
// 3、字符串类型(string)
var str: string = 'this is ts';
str = 'haha'; //正确

// 4、数组类型（array）
var arr: number[] = [11, 22, 33];
var arr5: Array<number> = [11, 22, 33];
let list: any[] = ['xcatliu', 25, { website: 'http://xcatliu.com' }];

// 5、元组类型（tuple）
var arr6: Array<number> = [11, 22, 33];
let arr7: [number, string] = [123, 'this is ts'];

// 6、枚举类型（enum）
// 随着计算机的不断普及，程序不仅只用于数值计算，还更广泛地用于处理非数值的数据。
// 例如：性别、月份、星期几、颜色、单位名、学历、职业等，都不是数值数据。
// 在其它程序设计语言中，一般用一个数值来代表某一状态，这种处理方法不直观，易读性差。
// 如果能在程序中用自然语言中有相应含义的单词来代表某一状态，则程序就很容易阅读和理解。
// 也就是说，事先考虑到某一变量可能取的值，尽量用自然语言中含义清楚的单词来表示它的每一个值，
// 这种方法称为枚举方法，用这种方法定义的类型称枚举类型。
enum Err { 'undefined' = -1, 'null' = -2, 'success' = 1 };


// 7、任意类型（any）
var oBox: any = document.getElementById('box');
oBox.style.color = 'red';

// 8、null 和 undefined
var num1: undefined;
//定义没有赋值就是undefined
var num2: null;
var num3: number | null | undefined;

// 9、void类型
// typescript中的void表示没有任何类型，一般用于定义方法的时候方法没有返回值。
function run(): void {
    console.log('run')
}
run();


// 10、never类型
// 是其他类型 （包括 null 和 undefined）的子类型，代表从不会出现的值。
var a2: never;
// a=123; //错误的写法
// a2 = (() => {
//     throw new Error('错误');
// })()

//11、 字符串字面量类型  用type定义
type EventNames = 'click' | 'scroll' | 'mousemove';
function handleEvent(ele: Element, event: EventNames) {
    // do something
}
// handleEvent(document.getElementById('hello'), 'scroll'); // 没问题
// handleEvent(document.getElementById('world'), 'dblclick'); // 报错，event 不能为 'dblclick'

// 12、类型别名
type Name = string;
type NameResolver = () => string;
type NameOrResolver = Name | NameResolver;
function getName(n: NameOrResolver): Name {
    if (typeof n === 'string') {
        return n;
    } else {
        return n();
    }
};

let myFavoriteNumber: string | number;
myFavoriteNumber = 'seven';
console.log(myFavoriteNumber.length); // 5
myFavoriteNumber = 7;
// console.log(myFavoriteNumber.length); // 编译时报错
// 只能访问此联合类型的所有类型里共有的属性或方法