
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/10/2022
 **/
public class _322_CoinChange {
    private static int inf = 10000000;

    public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);
        int[][] dp = new int[amount + 1][coins.length];
        Arrays.stream(dp)
                .forEach(row -> Arrays.fill(row, -1));
        dp[0][0] = 0;
        int leastChange = minExchange(coins, coins.length - 1, amount, dp);
        return leastChange == inf ? -1 : leastChange;

    }

    private int minExchange(int[] coins, int n, int amount, int[][] dp) {
        if (n < 0 && amount > 0) {
            return inf;
        }
        if (dp[amount][n] != -1) {
            return dp[amount][n];
        }

        int least = inf;

        if (amount - coins[n] >= 0) {
            least = Math.min(1 + minExchange(coins, n, amount - coins[n], dp), least);
        }
        least = Math.min(minExchange(coins, n - 1, amount, dp), least);
        return dp[amount][n] = least;

    }
}
