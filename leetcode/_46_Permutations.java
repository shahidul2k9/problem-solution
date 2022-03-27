
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;


/**
 * @author Shahidul Islam
 * @date 2/4/2022
 **/
public class _46_Permutations {
    public List<List<Integer>> permute(int[] nums) {
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
            for (int i = 0; i < n; i++) {
                if (!taken[i]) {
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
