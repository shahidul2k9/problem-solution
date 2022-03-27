
/**
 * @author Shahidul Islam
 * @date 2/7/2022
 **/
public class _209_MinimumSizeSubarraySum {
    public int minSubArrayLen(int target, int[] nums) {
        int left = 0;
        int s = 0;
        int l = Integer.MAX_VALUE;
        for (int right = 0; right < nums.length; right++) {
            s = s + nums[right];
            while (s - nums[left] >= target) {
                s = s - nums[left];
                left++;
            }
            if (s >= target) {
                l = Math.min(l, right - left + 1);
            }
        }
        if (l == Integer.MAX_VALUE) {
            return 0;
        } else {
            return l;
        }

    }
}
