
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/9/2022
 **/
public class _300_Longest_IncreasingSubsequence {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] lis = new int[n];
        int maxLis = 0;
        Arrays.fill(lis, -1);
        for (int i = 0; i < n; i++) {
            maxLis = Math.max(maxLis, findLisEndingAtIndex(nums, lis, i));
        }

        return maxLis;
    }

    private int findLisEndingAtIndex(int[] nums, int[] lis, int i) {
        if (lis[i] != -1) {
            return lis[i];
        } else {
            int maxLis = 1;
            for (int p = 0; p < i; p++) {
                if (nums[p] < nums[i])
                    maxLis = Math.max(maxLis, 1 + findLisEndingAtIndex(nums, lis, p));
            }
            return lis[i] = maxLis;
        }
    }
}
