import React from 'react';

export default class Algorithm extends React.Component {
    reserve = (num: number): number => {
        let me = num < 0 ? num * -1 : num;
        let arr = [];
        while (me / 10 > 0) {
            let remain = me % 10;
            me = Math.floor(me / 10);
            arr.push(remain)
        }
        console.log(Number(arr.join('')))
        let re = num > 0 ? Number(arr.join('')) : -1 * Number(arr.join(''))
        if (re > 214748364 || re < -214748364) return 0;
        return re
    }
    handleFilter=()=>{
        var removeDuplicates = function (nums:number[]) {
            var cur = nums[0];
            for (var i = 1; i < nums.length;) {
                if (nums[i] === cur)
                    nums.splice(i, 1);
                else
                    cur = nums[i++];
            }
            return nums.length
        };
        console.log(removeDuplicates([1,1,2,3,1]))
    }
    componentDidMount() {
        
    }
    render() {
        return (
            <div>
                <div>1.给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。</div>
                <button onClick={this.reserve.bind(this, 120)}>solution</button>
                <div>给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
                不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。</div>
                <button onClick={this.handleFilter}>solution</button>
            </div>
        )
    }
} 