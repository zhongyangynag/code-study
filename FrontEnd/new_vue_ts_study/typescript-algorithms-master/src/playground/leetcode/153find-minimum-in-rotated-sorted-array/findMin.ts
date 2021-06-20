export default function findMin(nums: number[]): number {
    let start = 0;
    let end = nums.length - 1;
    let pivot = nums[end];
    while (start <= end) {
        let middle = start + ((end - start) >> 1);
        if (nums[middle] <= pivot) {
            if (middle === 0 || nums[middle] < nums[middle - 1]) {
                return nums[middle];
            }
            end = middle - 1;
        } else if (nums[middle] > pivot) {
            start = middle + 1;
        }
    }
    return nums[0];
}

export function findMinPro(nums: number[]): number {
    let start = 0;
    let end = nums.length;
    let pivot = nums[end - 1];
    while (start < end) {
        let middle = start + ((end - start) >> 1);
        if (nums[middle] <= pivot) {
            end = middle;
        } else if (nums[middle] > pivot) {
            start = middle + 1;
        }
    }
    return start;
}

let res = findMinPro([5, 8, 2, 3]);
console.log(res);
