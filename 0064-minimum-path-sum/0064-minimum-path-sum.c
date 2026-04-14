/*
DP
Time: O(m*n)
*/
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int dp[m][n];

    dp[0][0] = grid[0][0];

    for (int i = 1; i < m; i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];

    for (int j = 1; j < n; j++)
        dp[0][j] = dp[0][j-1] + grid[0][j];

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++) {
            int minv = dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
            dp[i][j] = minv + grid[i][j];
        }

    return dp[m-1][n-1];
}