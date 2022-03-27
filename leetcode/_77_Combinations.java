
import java.util.ArrayList;
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 2/4/2022
 **/
public class _77_Combinations {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> combinationList = new ArrayList<>();
        generateCombinationList(n, k, 1, n, new ArrayList<>(), combinationList);
        return combinationList;

    }

    private void generateCombinationList(int n, int k, int a, int b, List<Integer> combination, List<List<Integer>> combinationList) {
        if (combination.size() == k) {
            combinationList.add(new ArrayList<>(combination));
        } else if (b - a + 1 + combination.size() >= k) {
            generateCombinationList(n, k, a + 1, b, combination, combinationList);

            combination.add(a);
            generateCombinationList(n, k, a + 1, b, combination, combinationList);
            combination.remove(combination.size() - 1);
        }
    }

}
