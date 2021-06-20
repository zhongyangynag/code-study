/* 可以把集合想象成一个既没有重复元素，也没有顺序概念的数组。 */

export default class Set {
    items:any={};
    //向集合添加一个新的项。
    add(value:any){
        if(!this.has(value)){
            this.items[value]=value
        }
    }
    //in操作符来验证给定的值是否是items对象的属性
    /* 但这个方法还有更好的实现方式，如下：
    this.has = function(value){
        return items.hasOwnProperty(value);
    };
    所有JavaScript对象都有hasOwnProperty方法。这个方法返回一个表明对象是否具有特定属
    性的布尔值 */
    has(value:any):boolean{
        return value in this.items
    }
    //从集合移除一个值。
    remove(value:any):boolean{
        if(this.has(value)){
            delete this.items[value];
            return true
        }else{
            return false
        }
    }
    //移除集合中的所有项。
    clear(){
        this.items={}
    }
    //返回集合所包含元素的数量。
    size():number{
        return Object.keys(this.items).length
    }
    //提取items对象的所有属性，以数组的形式返回
    values():string[]{
        return Object.keys(this.items)
    }

    /* 并集的数学概念，集合A和B的并集，表示为A∪B，定义如下：
    A∪B = { x | x ∈ A∨x ∈ B }
    意思是x（元素）存在于A中，或x存在于B中。 */
    union(otherSet:Set):Set{
        let unionSet = new Set();
        let values = this.values();
        let otherValues = otherSet.values();
        for (let index = 0; index < values.length; index++) {
            const element = values[index];
            unionSet.add(element);
        }
        for (let j = 0; j < otherValues.length; j++) {
            const element = otherValues[j];
            unionSet.add(element);
        }
        return unionSet
    }
    //交集
    intersection(otherSet:Set):Set{
        let intersectionSet = new Set();
        let values = this.values();
        for (let index = 0; index < values.length; index++) {
            const element = values[index];
            if(otherSet.has(element)){
                intersectionSet.add(element);
            }
            
        }
        return intersectionSet
    }

    /* 差集的数学概念，集合A和B的差集，表示为A-B，定义如下：
    A-B = { x | x ∈ A ∧ x B }
    意思是x（元素）存在于A中，且x不存在于B中。 */
    //交集
    difference(otherSet:Set):Set{
        let differenceSet = new Set();
        let values = this.values();
        for (let index = 0; index < values.length; index++) {
            const element = values[index];
            if(!otherSet.has(element)){
                differenceSet.add(element);
            }
        }
        return differenceSet
    }
    /* 子集的数学概念，集合A是B的子集（或集合B包含
了A），表示为A⊆ B，定义如下：
∀ x { x ∈ A → x ∈ B }
意思是集合A中的每一个x（元素），也需要存在于B中。 */
    subset(otherSet:Set):boolean{
        if(otherSet.size()<this.size()){
            return false
        }else{
            let values = this.values();
            for (let index = 0; index < values.length; index++) {
                const element = values[index];
                if(!otherSet.has(element)){
                    return false
                }
            }
            return true
        }
    }
}