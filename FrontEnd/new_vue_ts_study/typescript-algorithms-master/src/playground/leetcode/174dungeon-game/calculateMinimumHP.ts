export default function calculateMinimumHP(dungeon: number[][]): number {
    let n = dungeon.length;
    if (!n) return 0;
    let m = dungeon[0].length;

    let dp: number[][] = new Array(n);
    for (let i = 0; i < n + 1; i++) {
        dp[i] = new Array(m + 1).fill(Number.MAX_VALUE);
    }
    dp[n - 1][m] = dp[n][m - 1] = 1;

    for (let i = n - 1; i >= 0; i--) {
        for (let j = m - 1; j >= 0; j--) {
            let bestChoice = Math.min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = bestChoice - dungeon[i][j];
        }
    }
    return dp[0][0] <= 0 ? 0 : dp[0][0];
}

calculateMinimumHP([[0, 0]]);

/* 
 -2 (K)	-3	     3      
 -5	    -10	     1      1
 10	     30	    -5 (P)  
                 1
*/
