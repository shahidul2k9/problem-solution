
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/11/2022
 **/
public class _518_CoinChange2 {
    public int change(int amount, int[] coins) {
        int n = coins.length;
        int[][] dp = new int[amount + 1][n];
        Arrays.stream(dp)
                .forEach(row -> Arrays.fill(row, -1));
        return findWays(coins, n - 1, amount, dp);


    }

    private int findWays(int[] coins, int i, int amount, int[][] dp) {
        if (i < 0) {
            if (amount == 0)
                return 1;
            else return 0;
        } else if (dp[amount][i] != -1)
            return dp[amount][i];
        else {
            int w = 0;
            for (int c = 0; c * coins[i] <= amount; c++) {
                w = w + findWays(coins, i - 1, amount - c * coins[i], dp);
            }
            return dp[amount][i] = w;
        }
    }
}
