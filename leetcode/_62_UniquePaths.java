
/**
 * @author Shahidul Islam
 * @date 1/27/2022
 **/
public class _62_UniquePaths {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        for (int r = 0; r < m; r++) {
            dp[r][0] = 1;
        }
        for (int c = 0; c < n; c++) {
            dp[0][c] = 1;
        }
        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                dp[r][c] = dp[r][c - 1] + dp[r - 1][c];
            }
        }
        return dp[m - 1][n - 1];
    }
}
