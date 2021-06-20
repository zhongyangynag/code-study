export default function findDiagonalOrder(matrix: number[][]): number[] {
    let n = matrix.length;
    if (!n) return [];
    let m = matrix[0].length;
    let turns = 2 * n - 1;
    let res = [];
    let forward = true;
    let x = 0;
    let y = 0;
    res.push(matrix[0][0]);
    for (let i = 2; i < turns; i++) {
        let overHalf = i > Math.ceil(turns / 2);
        x = forward && !overHalf ? x + 1 : x;
        y = forward && !overHalf ? y : y + 1;
        forward = !forward;
        res.push(matrix[y][x]);
        if (forward) {
            while (y > 0 && x < n - 1) {
                x += 1;
                y -= 1;
                console.log([y, x]);
                res.push(matrix[y][x]);
            }
        } else {
            while (x > 0 && y < n - 1) {
                x -= 1;
                y += 1;
                console.log([y, x]);
                res.push(matrix[y][x]);
            }
        }
    }
    res.push(matrix[n - 1][n - 1]);

    return res;
}

function findDiagonalOrder2(matrix: number[][]): number[] {
    let n = matrix.length;
    let idxes = new Array(n).fill(0);
    let res = [];
    let m = matrix[0].length;
    let edge = Math.max(m, n);
    let levels = 2 * edge - 1;
    let towns = 1;
    let overHalf = false;
    for (let i = 0; i < levels; i++) {
        let idx = 0;
        overHalf = i >= Math.ceil(levels / 2);
        if (!overHalf) {
            while (idx < towns && idx < n) {
                res.push(matrix[idx][idxes[idx]]);
                idxes[idx]++;
                idx++;
            }
            towns++;
        } else {
            while (idx < towns) {
                if (edge - idx > n) {
                    idx++;
                    continue;
                }
                res.push(matrix[edge - idx][idxes[edge - idx]]);
                idxes[edge - idx]++;
                idx++;
            }
            towns--;
        }
    }
    return res;
}

let res = findDiagonalOrder2([
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
]);

console.log(res);
