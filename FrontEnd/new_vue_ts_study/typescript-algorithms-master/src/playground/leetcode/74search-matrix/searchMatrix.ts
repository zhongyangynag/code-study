export default function searchMatrix(
    matrix: number[][],
    target: number
): boolean {
    if (matrix.length === 0 || matrix[0].length === 0) return false;
    let i = binarySearch(matrix, target, getCompareEles);
    console.log(i);
    let j = binarySearch(matrix[i], target, getCompareEles);
    return matrix[i][j] === target;
}

type compareFunction = (arr: number[] | number[][], idx: number) => number;

function getCompareEles(arr: number[] | number[][], idx: number): number {
    let cArr;
    if (typeof arr[idx] === "number") {
        cArr = arr as number[];
        return cArr[idx];
    }
    cArr = arr as number[][];
    let i = cArr[0].length - 1;
    return cArr[idx][i];
}

function binarySearch(
    arr: number[] | number[][],
    target: number,
    callback: compareFunction
): number {
    let begin = 0,
        end = arr.length - 1,
        middle = end;
    while (begin <= end) {
        middle = begin + ((end - begin) >> 1);
        if (callback(arr, middle) > target) {
            let cEnd = end;
            end = middle - 1;
            middle = cEnd;
        } else if (callback(arr, middle) < target) {
            begin = middle + 1;
            middle = end;
        } else {
            return middle;
        }
    }
    return middle;
}

let matrix = [
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50],
];
let res = searchMatrix(matrix, 3);
console.log(res);
