export default function generate(numRows: number): number[][] {
    let result: number[][] = [];
    for (let i = 0; i < numRows; i++) {
        let rowLen = i + 1;
        let curRow = new Array(rowLen);
        for (let j = 0; j < rowLen; j++) {
            if (j === 0 || j === rowLen - 1) {
                curRow[j] = 1;
                continue;
            }
            curRow[j] = result[i - 1][j - 1] + result[i - 1][j];
        }
        result.push(curRow);
    }
    return result;
}

console.log(generate(5));
