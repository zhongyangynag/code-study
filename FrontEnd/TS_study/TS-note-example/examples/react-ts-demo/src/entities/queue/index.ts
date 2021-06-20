/* 
队列是遵循FIFO（First In First Out，先进先出，也称为先来先服务）原则的一组有序的项。
队列在尾部添加新元素，并从顶部移除元素。最新添加的元素必须排在队列的末尾
*/

export default class Queue<T>{
    items:T[]=[];
    //向队列尾部添加一个（或多个）新的项。
    enqueue(el:T):void{
        this.items.push(el)
    }
    //移除队列的第一（即排在队列最前面的）项，并返回被移除的元素。
    dequeue():T{
        return this.items.shift() as T
    }
    //返回队列中第一个元素——最先被添加，也将是最先被移除的元素。队列不做任何变动
    front():T{
        return this.items[0]
    }
    //如果队列中不包含任何元素，返回true，否则返回false
    isEmpey():boolean{
        return this.items.length === 0
    }
    //返回队列包含的元素个数，与数组的length属性类似
    size():number{
        return this.items.length
    }
}