import React from 'react';
import BinaryTree from '../../entities/binaryTree/BinaryTree'
import Stack from '../../entities/stack'
import LinkedList from '../../entities/linkedList'
import Set from '../../entities/set'

interface IProps { }
interface IState {
    arr: number[]
}
export default class PageDataStructure extends React.Component<IProps, IState>{
    constructor(props: IProps) {
        super(props);
        this.state = {
            arr: [1, 4, 2, 5, 6, 3, 56, 7, 64, 67, 86]
        }
    }
    handleBinary = () => {
        const arr = [6, 3, 5, 2, 4, 7, 11, 34];
        const tree = new BinaryTree(arr);
        tree.inOrder()
        console.log(tree)
    }
    handleStack = () => {
        const stack = new Stack<number>();
        console.log(stack.isEmpty())
        stack.push(1);
        stack.push(8);
        console.log(stack.peek());
        stack.push(5);
        console.log(stack.size());
        stack.pop();
        stack.print()
    }
    handleDivideBy2 = (num: number): string => {
        let remStack = new Stack<number>(),
            rem,
            binaryString = '';
        while (num > 0) {
            rem = Math.floor(num % 2);
            remStack.push(rem);
            num = Math.floor(num / 2)
        }
        while (!remStack.isEmpty()) {
            binaryString += remStack.pop().toString()
        }
        return binaryString
    }
    handleLinkedList = () => {
        let linkedList = new LinkedList();
        linkedList.append(123)
        console.log(linkedList)
    }
    handleUnionSet = () => {
        let set = new Set();
        set.add(2);
        set.add(5);
        let otherSet = new Set();
        otherSet.add(3);
        console.log(set.union(otherSet))
    }
    handleIntersectionSet = () => {
        let set = new Set();
        set.add(2);
        set.add(5);
        let otherSet = new Set();
        otherSet.add(3);
        otherSet.add("5");
        console.log(set.intersection(otherSet))
    }
    handleSubset = () => {
        let setA = new Set();
        setA.add(1);
        setA.add(2);
        let setB = new Set();
        setB.add(1);
        setB.add(2);
        setB.add(3);
        let setC = new Set();
        setC.add(2);
        setC.add(3);
        setC.add(4);
        console.log(setA.subset(setB));
        console.log(setA.subset(setC));
    }
    handleDiffence = () => {
        let setA = new Set();
        setA.add(1);
        setA.add(2);
        setA.add(3);
        let setB = new Set();
        setB.add(2);
        setB.add(3);
        setB.add(4);
        let differenceAB = setA.difference(setB);
        console.log(differenceAB.values());
    }
    swap = (num1: number, num2: number) => {
        let { arr } = this.state;
        let num = arr[num1];
        arr[num1] = arr[num2];
        arr[num2] = num;
    }
    /* 冒泡排序比较任何两个相邻的项，如果第一个比第二个大，则交换它们。元素项向上移动至
    正确的顺序，就好像气泡升至表面一样，冒泡排序因此得名。 */
    bubbleSort = (arr: number[]) => {
        console.log('unSorted:', arr)
        for (let i = 0, length = arr.length; i < length; i++) {
            for (let j = 0; j < length - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    this.swap(j, j + 1)
                }
            }
        }
        console.log('sorted', arr)
    }
    /* 选择排序大致的思路是找到数据结构中的最小值并
    将其放置在第一位，接着找到第二小的值并将其放在第二位，以此类推。 */
    selectionSort = (arr: number[]) => {
        console.log('unSorted:', arr)
        let length = arr.length, indexMin;
        for (let i = 0; i < length - 1; i++) {
            indexMin = i;
            for (let j = i; j < length; j++) {
                if (arr[indexMin] > arr[j]) {
                    indexMin = j
                }
            }
            if (i !== indexMin) {
                this.swap(i, indexMin)
            }
        }
        console.log('sorted', arr)
    }
    insertSort = (array: number[]) => {
        console.log('unSorted:', array);
        var length = array.length, //{1}
            j, temp;
        for (var i = 1; i < length; i++) { //{2}
            j = i; //{3}
            temp = array[i]; //{4}
            while (j > 0 && array[j - 1] > temp) { //{5}
                array[j] = array[j - 1]; //{6}
                j--;
            }
            array[j] = temp; //{7}
        }

        console.log('sorted', array)
    }
    render() {
        const { arr } = this.state;
        return (
            <div>
                <h3>二叉树</h3>
                <button onClick={this.handleBinary}>binary</button>
                <h3>栈</h3>
                <button onClick={this.handleStack}>stack</button>
                <div>十进制转二进制：{this.handleDivideBy2(125)}</div>
                <h3>链表</h3>
                <button onClick={this.handleLinkedList}>linkedList</button>
                <h3>集合</h3>
                <button onClick={this.handleUnionSet}>并集</button>
                <button onClick={this.handleIntersectionSet}>交集</button>
                <button onClick={this.handleSubset}>子集</button>
                <button onClick={this.handleDiffence}>差集</button>
                <h3>排序</h3>
                <button onClick={this.bubbleSort.bind(this, arr)}>冒泡排序</button>
                <button onClick={this.selectionSort.bind(this, arr)}>选择排序</button>
                <button onClick={this.insertSort.bind(this, arr)}>插入排序</button>
            </div>
        )
    }

}