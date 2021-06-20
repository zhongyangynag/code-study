import printMatrix from "../../../utils/leetcode/printMatrix.ts";
//      t
// l        r
//      b

function generateMatrix(n: number): number[][] {
    let matrix: number[][] = new Array(n);
    for (let i = 0; i < n; i++) {
        matrix[i] = new Array(n).fill(null);
    }

    let l = 0,
        t = 0,
        r = n - 1,
        b = n - 1,
        num = 1,
        total = n * n;

    while (num <= total) {
        for (let i = l; i <= r; i++) matrix[t][i] = num++;
        t++;
        for (let i = t; i <= b; i++) matrix[i][r] = num++;
        r--;
        for (let i = r; i >= l; i--) matrix[b][i] = num++;
        b--;
        for (let i = b; i >= t; i--) matrix[i][l] = num++;
        l++;
    }

    return matrix;
}

let matrix = generateMatrix(4);
printMatrix(matrix);
printMatrix(matrix);
