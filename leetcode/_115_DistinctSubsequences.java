
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/6/2022
 **/
public class _115_DistinctSubsequences {
    public int numDistinct(String s, String t) {
        int m = s.length();
        int n = t.length();
        int[][] dp = new int[m][n];
        Arrays.stream(dp)
                .forEach(row -> Arrays.fill(row, -1));
        return ways(dp, m - 1, n - 1, s, t);


    }

    private int ways(int[][] dp, int i, int j, String s, String t) {
        if (i < 0 || j < 0) {
            if (i < 0 && j >= 0) {
                return 0;
            } else {
                return 1;
            }
        } else if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int w;
        if (s.charAt(i) == t.charAt(j)) {
            w = ways(dp, i - 1, j - 1, s, t) + ways(dp, i - 1, j, s, t);
        } else {
            w = ways(dp, i - 1, j, s, t);
        }
        dp[i][j] = w;
        return w;

    }
}
