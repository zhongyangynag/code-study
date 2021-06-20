export default class NumMatrix {
    store?: number[][];
    constructor(matrix: number[][]) {
        let n = matrix.length;
        if (!n) return;
        let m = matrix[0].length;
        if (!m) return;
        this.store = new Array(n + 1);
        for (let i = 0; i < n + 1; i++) {
            this.store[i] = new Array(m + 1).fill(0);
        }

        for (let i = 0; i < n; i++) {
            for (let j = 0; j < m; j++) {
                this.store[i + 1][j + 1] =
                    matrix[i][j] +
                    this.store[i][j + 1] +
                    this.store[i + 1][j] -
                    this.store[i][j];
            }
        }
    }

    sumRegion(row1: number, col1: number, row2: number, col2: number): number {
        return this.store
            ? this.store[row2 + 1][col2 + 1] -
                  this.store[row1][col2 + 1] -
                  this.store[row2 + 1][col1] +
                  this.store[row1][col1]
            : 0;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * var obj = new NumMatrix(matrix)
 * var param_1 = obj.sumRegion(row1,col1,row2,col2)
 */
