
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/8/2022
 **/
public class _1289_MinimumFallingPathSumII {
    private static int inf = Integer.MAX_VALUE;

    public int minFallingPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] dp = new int[m][n];
        Arrays.stream(dp)
                .forEach(row -> Arrays.fill(row, inf));
        System.arraycopy(grid[0], 0, dp[0], 0, n);
        int mp = inf;
        for (int c = 0; c < n; c++) {
            mp = Math.min(minPath(grid, m, n, dp, m - 1, c), mp);
        }
        return mp;
    }

    private int minPath(int[][] grid, int m, int n, int[][] dp, int r, int c) {
        if (dp[r][c] != inf) {
            return dp[r][c];
        }
        int previousRowMin = inf;
        for (int k = 0; k < n; k++) {
            if (k != c) {
                previousRowMin = Math.min(previousRowMin, minPath(grid, m, n, dp, r - 1, k));
            }
        }
        return dp[r][c] = grid[r][c] + previousRowMin;
    }
}
