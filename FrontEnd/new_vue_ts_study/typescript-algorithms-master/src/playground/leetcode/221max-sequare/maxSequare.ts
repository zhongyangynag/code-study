export default function maximalSquare(matrix: string[][]): number {
    let n = matrix.length;
    if (!n) return 0;
    let m = matrix[0].length;
    let dp: number[][] = new Array(n);
    for (let i = 0; i < n; i++) {
        dp[i] = new Array(m).fill(0);
    }
    let res = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (matrix[i][j] === "0") {
                dp[i][j] = 0;
            } else if (i === 0 || j === 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] =
                    Math.min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1;
            }
            res = Math.max(dp[i][j], res);
        }
    }
    return res ** 2;
}

let matrix = [
    ["1", "0", "1", "0", "0"],
    ["1", "0", "1", "1", "1"],
    ["1", "1", "1", "1", "1"],
    ["1", "0", "1", "1", "1"],
];

// matrix = [["1"]];

let res = maximalSquare(matrix);
console.log(res);
