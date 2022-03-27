
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/17/2022
 **/
public class _375_GuessNumberHigherOrLowerII {
    public int getMoneyAmount(int n) {
        int[][] dp = new int[n + 1][n + 1];

        Arrays.stream(dp)
                .forEach(row -> Arrays.fill(row, -1));

        return findMinCost(1, n, dp);

    }

    private int findMinCost(int a, int b, int[][] dp) {
        if (a >= b) {
            return 0;
        } else if (dp[a][b] != -1) {
            return dp[a][b];
        } else {
            int cost = Integer.MAX_VALUE;
            for (int m = a; m <= b; m++) {
                int x = findMinCost(a, m - 1, dp);
                int y = findMinCost(m + 1, b, dp);
                cost = Math.min(cost, Math.max(x,y) + m);
            }
            dp[a][b] = cost;
            return cost;
        }
    }
}
