
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/8/2022
 **/
public class _931_MinimumFallingPathSum {
    private static int inf = Integer.MAX_VALUE;

    public int minFallingPathSum(int[][] grid) {

        int m = grid.length;
        int n = grid[0].length;
        int[][] dp = new int[m][n];
        Arrays.stream(dp)
                .forEach(row -> Arrays.fill(row, -1));
        System.arraycopy(grid[0], 0, dp[0], 0, n);
        int mp = inf;
        for (int c = 0; c < n; c++) {
            mp = Math.min(minPath(grid, m, n, dp, m - 1, c), mp);
        }
        return mp;
    }

    private int minPath(int[][] grid, int m, int n, int[][] dp, int r, int c) {
        if (r < 0 || c < 0 || r >= m || c >= n) {
            return inf;
        } else if (dp[r][c] != -1) {
            return dp[r][c];
        }
        return dp[r][c] = grid[r][c] +
                Math.min(Math.min(minPath(grid, m, n, dp, r - 1, c - 1), minPath(grid, m, n, dp, r - 1, c)),
                        minPath(grid, m, n, dp, r - 1, c + 1));
    }
}
