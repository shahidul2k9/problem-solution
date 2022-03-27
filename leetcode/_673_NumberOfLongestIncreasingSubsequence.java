
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/12/2022
 **/
public class _673_NumberOfLongestIncreasingSubsequence {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        int[] lis = new int[n];
        int[] dp = new int[n];
        Arrays.fill(lis, 1);
        Arrays.fill(dp, -1);
        int lisLength = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    lis[i] = Math.max(lis[i], lis[j] + 1);
                }
                lisLength = Math.max(lisLength, lis[i]);
            }
        }
        int total = 0;
        for (int i = lisLength - 1; i < n; i++) {
            if (lisLength == lis[i])
                total = total + countLis(nums, lis, i, dp);
        }
        return total;
    }

    private int countLis(int[] nums, int[] lis, int b, int[] dp) {
        if (dp[b] != -1) {
            return dp[b];
        }
        int s = 0;
        for (int i = 0; i < b; i++) {
            if (lis[i] + 1 == lis[b] && nums[i] < nums[b]) {
                s = s + countLis(nums, lis, i, dp);
            }
        }
        dp[b] = s == 0 ? 1 : s;
        return dp[b];
    }
}
