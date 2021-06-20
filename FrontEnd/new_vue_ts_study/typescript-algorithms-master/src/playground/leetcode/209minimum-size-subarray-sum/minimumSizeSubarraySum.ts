export default function minSubArrayLen(s: number, nums: number[]): number {
    let i = 0,
        j = 0,
        n = nums.length;
    if (n === 0) return 0;
    let min = Number.MAX_VALUE;
    let curSum = nums[i];
    while (i <= n - 1 && j < n) {
        while (curSum < s && j < n) {
            j = j + 1;
            curSum = curSum + nums[j];
        }
        if (curSum >= s) min = Math.min(min, j - i + 1);
        curSum -= nums[i++];
    }
    return min === Number.MAX_VALUE ? 0 : min;
}

let s = 11;
let nums = [1, 2, 3, 4, 5];
let res = minSubArrayLen(s, nums);
console.log(res);
