
/**
 * @author Shahidul Islam
 * @date 1/27/2022
 **/
public class _63_UniquePathsII {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m, n;
        m = obstacleGrid.length;
        n = obstacleGrid[0].length;
        int[][] dp = new int[m][n];
        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int r = 1; r < m; r++) {
            if (obstacleGrid[r][0] == 1) {
                dp[r][0] = 0;
            } else {
                dp[r][0] = dp[r - 1][0];
            }

        }
        for (int c = 1; c < n; c++) {
            if (obstacleGrid[0][c] == 1) {
                dp[0][c] = 0;
            } else {
                dp[0][c] = dp[0][c - 1];
            }
        }
        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                int ways = 0;
                if (obstacleGrid[r][c] == 0) {
                    ways = dp[r][c - 1] + dp[r - 1][c];
                }
                dp[r][c] = ways;
            }
        }
        return dp[m - 1][n - 1];
    }
}
