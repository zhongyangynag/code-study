/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */

export default function searchMatrix(
    matrix: number[][],
    target: number
): boolean {
    let n = matrix.length;
    if (n <= 0) return false;
    let m = matrix[0].length;
    let i = n - 1;
    let j = 0;

    while (i >= 0 && j < m) {
        let curr = matrix[i][j];
        if (curr === target) return true;
        if (curr > target) i--;
        if (curr < target) j++;
    }
    return false;
}

let matrix = [
    [1, 4, 7, 11, 15],
    [2, 5, 8, 12, 19],
    [3, 6, 9, 16, 22],
    [10, 13, 14, 17, 24],
    [18, 21, 23, 26, 30],
];

// 给定 target = 5，返回 true。
// 给定 target = 20，返回 false。
let res = searchMatrix(matrix, 25);
console.log(res);
