
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 1/28/2022
 **/
public class _39_CombinationSum {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> combinationList = new ArrayList<>();

        Arrays.sort(candidates);
        bk(0, 0, new ArrayList<>(), candidates, target, combinationList);
        return combinationList;
    }

    private void bk(int pos, int runningSum, List<Integer> runningCombination, int[] candidates, int target, List<List<Integer>> combinationList) {
        if (runningSum == target) {
            combinationList.add(new ArrayList<>(runningCombination));
            return;
        } else if (pos >= candidates.length) {
            return;
        }
        int val = candidates[pos];
        if (val + runningSum <= target) {
            runningCombination.add(val);
            bk(pos, runningSum + val, runningCombination, candidates, target, combinationList);
            runningCombination.remove(runningCombination.size() - 1);
            bk(pos + 1, runningSum, runningCombination, candidates, target, combinationList);
        }

    }


}
