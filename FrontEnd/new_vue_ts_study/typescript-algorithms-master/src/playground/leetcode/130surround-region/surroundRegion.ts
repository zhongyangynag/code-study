/**
 Do not return anything, modify board in-place instead.
 [
     o, o, x, x
     x, o, x, o
     x, x, o, x
     o, o, x, o
 ]
 */

function solve(board: string[][]): void {
    let n = board.length;
    if (!n) return;
    let m = board[0].length;
    var visited = new Array(n);
    for (let i = 0; i < n; i++) {
        visited[i] = new Array(m).fill(false);
    }
    var rem: number[][] = [];
    for (let i = 0; i < n; i++) {
        dfs(board, visited, rem, 0, i);
        dfs(board, visited, rem, m - 1, i);
    }
    for (let i = 1; i < m - 1; i++) {
        dfs(board, visited, rem, i, 0);
        dfs(board, visited, rem, i, n - 1);
    }
    for (var i = 0; i < n; i++) {
        board[i] = new Array(m).fill("X");
    }
    rem.forEach((square) => {
        board[square[0]][square[1]] = "O";
    });
}

function dfs(
    board: string[][],
    visited: boolean[][],
    rem: number[][],
    x: number,
    y: number
) {
    if (visited[y][x] || board[y][x] === "X") {
        return false;
    }
    rem.push([y, x]);
    visited[y][x] = true;
    if (x < board[0].length - 1 && dfs(board, visited, rem, x + 1, y)) {
        return true;
    } else if (y < board.length - 1 && dfs(board, visited, rem, x, y + 1)) {
        return true;
    } else if (x > 0 && dfs(board, visited, rem, x - 1, y)) {
        return true;
    } else if (y > 0 && dfs(board, visited, rem, x, y - 1)) {
        return true;
    }
    return false;
}

// when is my girl friend`s birthday.
let board = [
    ["X", "O", "X", "O", "X", "O"],
    ["O", "X", "O", "X", "O", "X"],
    ["X", "O", "X", "O", "X", "O"],
    ["O", "X", "O", "X", "O", "X"],
];
solve(board);
console.log(board);
