
interface IDictionary{
    //向字典中添加新元素。
    set(key:string,value:any):void;
    //通过使用键值来从字典中移除键值对应的数据值。
    remove(key:string):boolean;
    //如果某个键值存在于这个字典中，则返回true，反之则返回false
    has(key:string):boolean;
    //通过键值查找特定的数值并返回
    get(key:string):any;
    //将这个字典中的所有元素全部删除
    clear():void;
    //返回字典所包含元素的数量。
    size():number;
    //将字典所包含的所有键名以数组形式返回
    keys():string[];
    //将字典所包含的所有数值以数组形式返回
    values():any[];
}


export default class Dictionary implements IDictionary{
    items:any={}
    set(key:string,value:any){
        if(!this.has(key)){
            this.items[key]=value
        }
    }
    has(key:string):boolean{
        return key in this.items;
    }
    remove(key:string):boolean{
        if(this.has(key)){
            delete this.items[key]
            return true
        }else{
            return false
        }
    }
    get(key:string):any{
        if(this.has(key)){
            return this.items[key]
        }else{
            return undefined
        }
    }
    clear(){
        this.items={}
    }
    size():number{
        return Object.keys(this.items).length
    }
    keys():string[]{
        return Object.keys(this.items)
    }
    values():any[]{
        let arr:any[]=[];
        for (const key in this.items) {
            if (this.items.hasOwnProperty(key)) {
                const element = this.items[key];
                arr.push(element)
            }
        }
        return arr
    }
}