
import java.util.HashMap;
import java.util.Map;

/**
 * @author Shahidul Islam
 * @date 2/11/2022
 **/
public class _494_TargetSum {
    public int findTargetSumWays(int[] nums, int target) {
        Map<String, Integer> dp = new HashMap<>();
        return findSum(nums, nums.length - 1, target, dp);

    }

    private int findSum(int[] nums, int cn, int target, Map<String, Integer> dp) {
        String key = cn + "-" + target;
        if (cn < 0) {
            if (target == 0)
                return 1;
            else
                return 0;
        } else if (dp.containsKey(key))
            return dp.get(key);
        else {
            int ways = findSum(nums, cn - 1, target + nums[cn], dp)
                    + findSum(nums, cn - 1, target - nums[cn], dp);
            dp.put(key, ways);
            return ways;
        }
    }
}
