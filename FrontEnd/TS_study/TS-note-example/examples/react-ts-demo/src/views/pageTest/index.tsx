import React from 'react';

export default class PageTest extends React.Component {
    testVar=(obj:any)=>{
        // obj={name:1}
        obj.name='123'
        return obj
    }
    testArr=(arr:any[])=>{
        let newArr = [...arr];
        newArr.splice(1,1)
        console.log(newArr)
        return newArr
    }
    testFunction=()=>{
        let fn=function f(params:number) {
            console.log(f)
        }
        console.log(typeof fn)
        fn(1)
    }
    /* 工厂模式虽然解决了创建
    多个相似对象的问题，但却没有解决对象识别的问题（即怎样知道一个对象的类型） */
    factortyMode=()=>{
        function createPerson(name:string) {
            let o:any = {};
            o.name = name;
            return o;
        }
        let person = createPerson('king');
        console.log(person)
    }
    /* 要创建 Person 的新实例，必须使用 new 操作符。以这种方式调用构造函数实际上会经历以下 4
    个步骤：
    (1) 创建一个新对象；
    (2) 将构造函数的作用域赋给新对象（因此 this 就指向了这个新对象）；
    (3) 执行构造函数中的代码（为这个新对象添加属性）；
    (4) 返回新对象。 */
    constructorMode=()=>{
        // function Person(name:string) {
        //     this.name = name;
        // }
        // let person = new Person('king')
        // console.log(person)
    }
    /* 原型模式
    每个函数都有一个 prototype（原型）属性，这个属性是一个指针，指向一个对象，
    而这个对象的用途是包含可以由特定类型的所有实例共享的属性和方法。 */
    protoMode=()=>{
        /* Person.prototype. constructor 指向 Person。 */
        function Person() {
            
        }
        Person.prototype.name='king';
        // let person = new Person();
        // console.log(person)

    }
    componentDidMount(){
        // let obj= new Object()
        // console.log(this.testVar(obj));
        // console.log(obj)
        // let arr = [1,2,3]; 
        // console.log(this.testArr(arr))
        // console.log(arr)
        // let obj1={name:'123'};
        // let obj2=obj1;
        // obj2.name='1234';
        // obj2=null as any;

        // console.log(obj1,obj2)

        // let colors = [{text:'red'},{text:'green'}]
        // console.log(colors.toLocaleString(),colors.toString(),colors.values())
        // let nums = [1,2];
        // let nums2 = nums.concat();
        // nums2.splice(1,1);
        // console.log(nums,nums2)

        // let date = new Date();
        // console.log(date.toString(),date.toDateString(),date.toTimeString());

        this.testFunction()
    }
    render(){
        return (
            <div>
                <h3>设计模式</h3>
                <button onClick={this.factortyMode}>工厂模式</button>
            </div>
        )
    }
}