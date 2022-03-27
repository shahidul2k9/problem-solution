
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/18/2022
 **/
public class _377_CombinationSumIV {
    public int combinationSum4(int[] nums, int target) {
        int n = nums.length;
        int[] dp = new int[target + 1];
        Arrays.fill(dp, -1);
        return way(nums, target, dp);

    }

    private int way(int[] nums, int target, int[] dp) {
        if (target == 0)
            return 1;
        else if (dp[target] != -1)
            return dp[target];
        else {
            int w = 0;
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] <= target) {
                    w = w + way(nums, target - nums[i], dp);
                }
            }

            return dp[target] = w;
        }
    }
}
