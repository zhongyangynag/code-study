export default class NumArray {
    sumArray: number[];
    constructor(nums: number[]) {
        let n = nums.length;
        this.sumArray = new Array(n + 1).fill(0);
        for (let i = 0; i < n; i++) {
            this.sumArray[i + 1] = this.sumArray[i] + nums[i];
        }
    }

    sumRange(i: number, j: number): number {
        return this.sumArray[j + 1] - this.sumArray[i];
    }
}
