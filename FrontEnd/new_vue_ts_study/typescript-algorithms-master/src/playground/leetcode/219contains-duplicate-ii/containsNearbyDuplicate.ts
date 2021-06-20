function containsNearbyDuplicate(nums: number[], k: number): boolean {
    const m = new Map();
    for (let i = 0; i < nums.length; i++) {
        if (m.has(nums[i]) && i - m.get(nums[i]) <= k) return true;
        m.set(nums[i], i);
    }
    return false;
}

let nums = [1, 2, 3, 1, 2, 3],
    k = 2;
let res = containsNearbyDuplicate(nums, k);
console.log(res);
