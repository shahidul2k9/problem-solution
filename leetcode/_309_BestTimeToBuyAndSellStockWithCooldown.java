
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/13/2022
 **/
public class _309_BestTimeToBuyAndSellStockWithCooldown {
    private static final int BUY = 0;
    private static final int SELL = 1;
    private static final int COOLDOWN = 2;

    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][] dp = new int[n][3];
        Arrays.stream(dp)
                .forEach(row-> Arrays.fill(row, -1));
        dp[0][BUY] = 0;
        dp[0][SELL] = 0;
        dp[0][COOLDOWN] = 0;

        return Math.max(findMaxProfit(prices, n - 1, BUY, dp),
                Math.max(findMaxProfit(prices, n - 1, SELL, dp),
                        findMaxProfit(prices, n - 1, COOLDOWN, dp)));

    }

    private int findMaxProfit(int[] prices, int pos, int op, int[][] dp) {
        if (dp[pos][op] != -1) {
            return dp[pos][op];
        } else {
            int mf = 0;
            for (int i = 0; i < pos; i++) {
                if (op == BUY) {
                    mf = Math.max(mf, findMaxProfit(prices, i, COOLDOWN, dp));
                } else if (op == SELL && prices[i] < prices[pos]) {
                    mf = Math.max(mf, prices[pos] - prices[i] + findMaxProfit(prices, i, BUY, dp));
                } else if (op == COOLDOWN) {
                    mf = Math.max(mf, findMaxProfit(prices, i, SELL, dp));
                }
                dp[pos][op] = mf;
            }
            return mf;
        }
    }
}
