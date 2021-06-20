/**
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
说明:
    返回的下标值（index1 和 index2）不是从零开始的。
    你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 */
export default function twoSum(numbers: number[], target: number): number[] {
    let n = numbers.length;
    let start = 0;
    for (let i = n - 1; i >= 0; i--) {
        let pivot = target - numbers[i];
        let end = i;
        while (start <= end) {
            let mid = start + ((end - start) >> 1);
            console.log(start, mid, end);
            if (numbers[mid] > pivot) {
                end = mid - 1;
            } else if (numbers[mid] < pivot) {
                start = mid + 1;
            } else {
                return [mid + 1, i + 1];
            }
        }
        start = 0;
    }
    return [-1, -1];
}

let numbers = [-1, 0],
    target = -1;
console.log(twoSum(numbers, target));
