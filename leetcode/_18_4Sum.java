
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 1/29/2022
 **/
public class _18_4Sum {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> tupleList = new ArrayList<>();
        Arrays.sort(nums);
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (i == 0 || nums[i - 1] != nums[i]) {
                for (int j = i + 1; j < n; j++) {
                    if (j == i + 1 || nums[j - 1] != nums[j]) {
                        int low = j + 1;
                        int high = n - 1;
                        while (low < high) {
                            int s = nums[i] + nums[j] + nums[low] + nums[high];

                            if (s <= target) {
                                if (s == target) {
                                    tupleList.add(Arrays.asList(nums[i], nums[j], nums[low], nums[high]));
                                }
                                low++;
                                while (low < n && nums[low - 1] == nums[low]) low++;
                            } else {
                                high--;
                            }
                        }
                    }
                }
            }
        }

        return tupleList;
    }
}
