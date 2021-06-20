/* 
链表存储有序的元素集合，但不同于数组，链表中的元素在内存中并不是连续放置的。每个
元素由一个存储元素本身的节点和一个指向下一个元素的引用（也称指针或链接）组成。 */

class Node{
    element:number;
    next:Node|null;
    constructor(element:number){
        this.element=element;
        this.next=null;
    }
}

export default class LinkedList{
    head:Node|null=null;
    private length:number=0;
    append(el:number){
        let node = new Node(el);
        let current;
        if(this.head===null){
            this.head=node
        }else{
            current=this.head;
            while(current.next!==null){
                current=current.next
            }
            current.next=node;
        }
        this.length++
    }
    removeAt(position:number){
        if(position>-1 && position<this.length){
            let current:any = this.head;
            let previous:any,index=0;
            if(position===0 && current){
                this.head = current.next;
            }else{
                while(index++<position){
                    previous=current;
                    current=current.next
                }
                previous.next=current.next
            }
            this.length--;
            return current.element
        }else{
            return null
        }
    }
}