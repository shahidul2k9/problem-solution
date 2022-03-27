
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/5/2022
 **/
public class _44_WildcardMatching {
    public boolean isMatch(String s, String p) {
        int m = s.length();
        int n = p.length();
        int[][] dp = new int[m][n];
        Arrays.stream(dp).forEach(row -> Arrays.fill(row, -1));
        return  match(dp, m - 1, n - 1, s, p) == 1;

    }

    private int match(int[][] dp, int i, int j, String s, String p) {
        if (i < 0 || j < 0) {
            if (i < 0 && j < 0) {
                return 1;
            } else if (i < 0) {
                return isAllStarPrefix(p, j) ? 1 : 0;
            } else return 0;
        } else if (dp[i][j] >= 0) {
            return dp[i][j];
        } else {
            char pch = p.charAt(j);
            int val = 0;
            if (pch == '?') {
                val = match(dp, i - 1, j - 1, s, p);
            } else if (pch == '*') {
                val = Math.max(match(dp, i, j - 1, s, p), match(dp, i - 1, j, s, p));
            } else if (s.charAt(i) == p.charAt(j)) {
                val = match(dp, i - 1, j - 1, s, p);
            }
            dp[i][j] = val;
            return val;
        }
    }

    private boolean isAllStarPrefix(String p, int inclusiveEndIndex) {
        for (int i = 0; i <= inclusiveEndIndex; i++) {
            if (p.charAt(i) != '*') return false;
        }
        return true;
    }
}
