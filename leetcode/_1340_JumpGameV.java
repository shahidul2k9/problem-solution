
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/8/2022
 **/
public class _1340_JumpGameV {
    public int maxJumps(int[] arr, int d) {
        int n = arr.length;
        int[] dp = new int[n];
        Arrays.fill(dp, -1);
        int mj = 0;
        for (int i = 0; i < n; i++) {
            mj = Math.max(mj, 1 + jump(dp, arr, i, d));
        }
        return mj;

    }

    private int jump(int[] dp, int[] arr, int i, int d) {
        if (dp[i] != -1)
            return dp[i];
        int mj = 0;
        for (int left = i - 1; left >= i - d && left >= 0 && arr[left] < arr[i]; left--) {
            mj = Math.max(mj, 1 + jump(dp, arr, left, d));
        }
        for (int right = i + 1; right <= i + d && right < arr.length && arr[right] < arr[i]; right++) {
            mj = Math.max(mj, 1 + jump(dp, arr, right, d));
        }
        dp[i] = mj;
        return mj;
    }
}
