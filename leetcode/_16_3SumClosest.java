
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 1/29/2022
 **/
public class _16_3SumClosest {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        int globalDiff = 100000000;
        int globalSum = 0;

        for (int i = 0; i < n; i++) {
            int low = i + 1;
            int high = n - 1;
            while (low < high) {
                int localSum = nums[i] + nums[low] + nums[high];
                int localDiff = Math.abs(target - localSum);

                if (localSum < target) {
                    low++;
                } else {
                    high--;
                }
                if (localDiff < globalDiff) {
                    globalDiff = localDiff;
                    globalSum = localSum;

                }
            }
        }

        return globalSum;
    }
}
