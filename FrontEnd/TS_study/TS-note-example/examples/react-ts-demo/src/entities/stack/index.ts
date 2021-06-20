/* 
栈是一种遵从后进先出（LIFO）原则的有序集合。新添加的或待删除的元素都保存在栈的
末尾，称作栈顶，另一端就叫栈底。在栈里，新元素都靠近栈顶，旧元素都接近栈底
 */



export default class Stack<T> {
    items:T[]=[];
    //往栈里添加新元素
    push(item:T):void{
        this.items.push(item)
    }
    //移除栈顶的元素，同时返回被移除的元素,栈遵从LIFO原则，因此移出的是最后添加进去的元素。
    pop():T{
        return this.items.pop() as T
    }
    //返回栈顶的元素，不对栈做任何修改（这个方法不会移除栈顶的元素，仅仅返回它）
    peek():T{
        const len = this.items.length;
        return this.items[len-1] as T
    }
    //如果栈为空的话将返回true，否则就返回false
    isEmpty():boolean{
        return this.items.length === 0
    }
    //对于集合，最好用size代替length。因为栈的内部使用数组保存元素，所以能简单地返回栈的长度
    size():number{
        return this.items.length
    }
    //clear方法用来移除栈里所有的元素，把栈清空
    clear():void{
        this.items = []
    }
    //输出打印
    print():void{
        console.log(this.items.toString())
    }
}