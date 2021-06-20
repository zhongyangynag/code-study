export default function spiralOrder(matrix: number[][]): number[] {
    let m = matrix.length;
    if (!m) return [];
    let n = matrix[0].length;
    let res: number[] = [],
        l = 0,
        t = 0,
        r = n - 1,
        b = m - 1,
        total = m * n;

    while (total >= 1) {
        for (let i = l; i <= r && total >= 1; i++) {
            res.push(matrix[t][i]);
            total--;
        }
        t++;
        for (let i = t; i <= b && total >= 1; i++) {
            res.push(matrix[i][r]);
            total--;
        }
        r--;
        for (let i = r; i >= l && total >= 1; i--) {
            res.push(matrix[b][i]);
            total--;
        }
        b--;
        for (let i = b; i >= t && total >= 1; i--) {
            res.push(matrix[i][l]);
            total--;
        }
        l++;
    }

    return res;
}

let res = spiralOrder([
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12],
    [13, 14, 15, 16],
]);

console.log(res);
