export default function findMin(nums: number[]): number {
    let start = 0,
        end = nums.length - 1;
    while (start < end) {
        let middle = start + ((end - start) >> 1);
        if (nums[middle] > nums[end]) {
            start = middle + 1;
        } else if (nums[middle] < nums[end]) {
            end = middle;
        } else {
            end--;
        }
    }
    return nums[end];
}

// [3 ,1 ,3]
//  0  1  2
//     1
// s   e
// 0
