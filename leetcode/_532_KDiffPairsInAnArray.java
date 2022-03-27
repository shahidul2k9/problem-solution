
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * @author Shahidul Islam
 * @date 2/17/2022
 **/
public class _532_KDiffPairsInAnArray {
    public int findPairs(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        Set<Integer> processed = new HashSet<>();
        for (int key : nums) {
            map.put(key, map.getOrDefault(key, 0) + 1);
        }
        int total = 0;
        for (int key : nums) {
            Integer f = map.getOrDefault(key - k, 0);
            if (!processed.contains(key) && f > 0) {
                if (k == 0) {
                    total = total + (f > 1 ? 1 : 0);
                } else {
                    total = total + 1;
                }
                processed.add(key);
            }
        }
        return total;
    }
}
