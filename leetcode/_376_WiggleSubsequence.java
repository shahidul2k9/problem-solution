
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/18/2022
 **/
public class _376_WiggleSubsequence {
    public int wiggleMaxLength(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][2];

        Arrays.stream(dp)
                .forEach(row-> Arrays.fill(row, -1));
        int ml = 0;
        for (int i = 0; i < n; i++) {
            ml = Math.max(ml, Math.max(findMaxLength(nums, i, 0, dp), findMaxLength(nums, i, 1, dp)));
        }
        return ml;

    }

    private int findMaxLength(int[] nums, int pos, int sign, int[][] dp) {
        if (pos < 0)
            return 0;
        else if (pos == 0) {
            return 1;
        } else if (dp[pos][sign] != -1)
            return dp[pos][sign];
        else {
            int ml = 0;
            for (int i = 0; i < pos; i++) {
                int d = nums[pos] - nums[i];
                if (d > 0 && sign == 0)
                    ml = Math.max(ml, 1 + findMaxLength(nums, i, 1, dp));
                else if (d < 0 && sign == 1)
                    ml = Math.max(ml, 1 + findMaxLength(nums, i, 0, dp));
                /*else
                    ml = Math.max(ml, Math.max(findMaxLength(nums, i, 0, dp), findMaxLength(nums, i, 1, dp)));*/
            }
            dp[pos][sign] = ml;
            return ml;
        }
    }
}
