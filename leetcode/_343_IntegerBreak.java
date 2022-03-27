
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 1/27/2022
 **/
public class _343_IntegerBreak {
    private static int[] dp = new int[59];
    static {
        Arrays.fill(dp, 0);
        dp[1] = 1;
        for (int i = 2; i < dp.length;i++){
            for (int j = 1; j < i; j++){
                dp[i] = Math.max(dp[j] * dp[i-j], dp[i]);
                dp[i] = Math.max(j * dp[i-j], dp[i]);
                dp[i] = Math.max(dp[j] * (i-j), dp[i]);
                dp[i] = Math.max(j * (i-j), dp[i]);
            }
        }
    }
    public int integerBreak(int n) {
        return dp[n];
    }
}
