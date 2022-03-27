
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 1/29/2022
 **/
public class _16_3SumClosestO3 {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        int globalDiff = 100000000;
        int globalSum = 0;
        for (int i = 0; i < n;i++){
            if (i == 0 || nums[i] != nums[i - 1]){
                for (int j = i + 1; j < n;j++){
                    if (j == i + 1 || (nums[j] != nums[j-1]) ){
                        for (int k = j + 1; k < n;k++){
                            int sum = nums[i] + nums[j] + nums[k];
                            int diff = Math.abs(sum - target);
                            if (diff < globalDiff){
                                globalSum = sum;
                                globalDiff = diff;
                            }
                        }
                    }
                }

            }
        }

        return globalSum;
    }
}
