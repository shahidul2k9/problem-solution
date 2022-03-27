
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 1/26/2022
 **/
public class _91_DecodeWays {
    public int numDecodings(String s) {
        int length = s.length();
        int[] ways = new int[length];
        Arrays.fill(ways, -1);

        return dfs(0, s, ways);

    }

    private int dfs(int i, String s, int[] ways) {
        if (i > s.length()) {
            return 0;
        } else if (i == s.length()) {
            return 1;
        } else if (ways[i] != -1) {
            return ways[i];
        } else if (s.charAt(i) == '0') {
            return 0;
        }
        int tt = dfs(i + 1, s, ways);

        char currentChart = s.charAt(i);
        if (i + 1 < s.length()) {
            char nextChar = s.charAt(i + 1);
            int combinedCharValue = (currentChart - '0') * 10 + nextChar - '0';
            if (combinedCharValue >= 10 && combinedCharValue < 27) {
                tt += dfs(i + 2, s, ways);
            }
        }
        ways[i] = tt;

        return tt;
    }
}
