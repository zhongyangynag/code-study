export default function search(nums: number[], target: number): number {
    let n = nums.length;
    if (!n) return -1;
    let left = 0,
        right = n,
        pivot = nums[n - 1];
    if (pivot === target) return n - 1;
    while (left < right) {
        let middle = left + ((right - left) >> 1);
        if (nums[middle] === target) {
            return middle;
        } else if (nums[middle] > target) {
            if (target < pivot) {
                if (nums[middle] > pivot) {
                    left = middle + 1;
                } else {
                    right = middle;
                }
            } else {
                right = middle;
            }
        } else if (nums[middle] < target) {
            if (target > pivot) {
                if (nums[middle] > pivot) {
                    left = middle + 1;
                } else {
                    right = middle;
                }
            } else {
                left = middle + 1;
            }
        }
    }
    return -1;
}

console.log(search([4, 5, 6, 7, 0, 1, 2], 2));
for (let i = 0; i < 8; i++) {
    console.log(search([4, 5, 6, 7, 0, 1, 2], i), i);
}
