# 179. 最大数
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

#### 示例:

```ts
输入: [10,2]
输出: 210

输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
```

#### 解答:

```ts
function largestNumber(nums: number[]): string {
    nums.sort(sortCallbackPro);
    return nums[0] ? nums.join("") : "0";
}

function sortCallbackPro(a: number, b: number): number {
    let S1 = `${a}${b}`;
    let S2 = `${b}${a}`;
    return Number(S2) - Number(S1);
}


console.log(largestNumber([3, 30, 34, 5, 9]));
```