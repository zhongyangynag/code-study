function numIslands(grid: string[][]): number {
    if (!grid || !grid[0]) return 0;
    let row = grid.length;
    let col = grid[0].length;
    let count = 0;
    for (let i = 0; i < row; i++) {
        for (let j = 0; j < col; j++) {
            if (grid[i][j] === "1") {
                count++;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}

function dfs(grid: string[][], y: number, x: number) {
    let row = grid.length;
    let col = grid[0].length;
    if (y < 0 || x < 0 || y >= row || x >= col || grid[y][x] === "0") {
        return;
    }
    grid[y][x] = "0";
    dfs(grid, y, x + 1);
    dfs(grid, y + 1, x);
    dfs(grid, y, x - 1);
    dfs(grid, y - 1, x);
}

console.log(Boolean([]));
