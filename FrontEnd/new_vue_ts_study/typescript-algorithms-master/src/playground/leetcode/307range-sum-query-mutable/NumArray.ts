export default class NumArray {
    sumArray: number[];
    nums: number[];
    constructor(nums: number[]) {
        let n = nums.length;
        this.nums = nums;
        this.sumArray = new Array(n + 1).fill(0);
        for (let i = 0; i < n; i++) {
            this.sumArray[i + 1] = this.sumArray[i] + nums[i];
        }
    }

    sumRange(i: number, j: number): number {
        return this.sumArray[j + 1] - this.sumArray[i];
    }

    update(i: number, val: number): void {
        let sub = val - this.nums[i];
        this.nums[i] = val;
        for (i = i + 1; i < this.sumArray.length; i++) {
            this.sumArray[i] += sub;
        }
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * obj.update(i,val)
 * var param_2 = obj.sumRange(i,j)
 */
