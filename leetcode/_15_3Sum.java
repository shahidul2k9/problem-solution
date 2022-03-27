
import java.util.*;

/**
 * @author Shahidul Islam
 * @date 1/29/2022
 **/
public class _15_3Sum {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> tripletList = new ArrayList<>();
        Arrays.sort(nums);
        int n = nums.length;
        int s;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;

            int secondIndex = -1;
            for (int j = i + 1; j < n; j++) {
                if (secondIndex == -1 || nums[j] != nums[secondIndex]){
                    int thirdElementIndex = Arrays.binarySearch(nums, j + 1, n, 0 - nums[i] - nums[j]);
                    if (thirdElementIndex >= 0) {
                        secondIndex = j;
                        tripletList.add(Arrays.asList(nums[i], nums[j], nums[thirdElementIndex]));
                    }
                }

            }
        }
        return tripletList;
    }
}
