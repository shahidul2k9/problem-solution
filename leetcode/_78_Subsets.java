
import java.util.ArrayList;
import java.util.List;

class _78_Subsets {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> powerSet = new ArrayList<>();
        int n = nums.length;
        for (int i = 0; i < (1 << n); i++) {
            ArrayList<Integer> subset = new ArrayList<>();
            for (int k = 0; k < n; k++) {
                if (((1 << k) & i) != 0) {
                    subset.add(nums[k]);
                }
            }
            powerSet.add(subset);
        }

        return powerSet;
    }
}