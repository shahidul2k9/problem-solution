
import java.util.ArrayList;
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 1/28/2022
 **/
public class _216_CombinationSumIII {
    private static int[] digits = new int[9];

    static {
        for (int i = 0; i < digits.length; i++) {
            digits[i] = i + 1;
        }
    }

    public List<List<Integer>> combinationSum3(int k, int n) {

        List<List<Integer>> combinationList = new ArrayList<>();

        bk(0, 0, new ArrayList<>(), digits, k, n, combinationList);
        return combinationList;
    }

    private void bk(int pos, int runningSum, List<Integer> runningCombination, int[] candidates, int allowedElementCount, int target, List<List<Integer>> combinationList) {
        if (runningSum == target) {
            if (allowedElementCount == runningCombination.size()) {
                combinationList.add(new ArrayList<>(runningCombination));
            }
            return;
        } else if (pos >= candidates.length) {
            return;
        }
        int val = candidates[pos];
        if (val + runningSum <= target && allowedElementCount > runningCombination.size()) {
            runningCombination.add(val);
            bk(pos+1, runningSum + val, runningCombination, candidates, allowedElementCount, target, combinationList);
            runningCombination.remove(runningCombination.size() - 1);
            bk(pos + 1, runningSum, runningCombination, candidates, allowedElementCount, target, combinationList);
        }

    }
}
