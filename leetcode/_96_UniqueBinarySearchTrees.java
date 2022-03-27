
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/20/2022
 **/
public class _96_UniqueBinarySearchTrees {
    public int numTrees(int n) {
        int[][] dp = new int[n + 1][n + 1];
        Arrays.stream(dp)
                .forEach(row -> Arrays.fill(row, -1));
        return countBst(1, n, dp);
    }

    private int countBst(int a, int b, int[][] dp) {
        if (a >= b)
            return 1;
        else if (dp[a][b] != -1)
            return dp[a][b];
        else {
            int tc = 0;
            for (int i = a; i <= b; i++) {
                tc = tc + countBst(a, i - 1, dp) * countBst(i + 1, b, dp);
            }
            return dp[a][b] = tc;
        }
    }
}
