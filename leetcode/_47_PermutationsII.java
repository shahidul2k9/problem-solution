
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 2/5/2022
 **/
public class _47_PermutationsII {
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        List<List<Integer>> permutationList = new ArrayList<>();
        boolean[] taken = new boolean[nums.length];
        Arrays.fill(taken, false);
        generatePermutationList(nums, n, 0, taken, new ArrayList<Integer>(), permutationList);
        return permutationList;

    }

    private void generatePermutationList(int[] nums, int n, int cn, boolean[] taken, List<Integer> takenList, List<List<Integer>> permutationList) {
        if (cn == n) {
            permutationList.add(new ArrayList(takenList));
        } else {
            int prev = 10000;
            for (int i = 0; i < n; i++) {
                if (!taken[i] && nums[i] != prev) {
                    prev = nums[i];
                    taken[i] = true;
                    takenList.add(nums[i]);
                    generatePermutationList(nums, n, cn + 1, taken, takenList, permutationList);
                    takenList.remove(takenList.size() - 1);
                    taken[i] = false;
                }
            }
        }
    }

}
