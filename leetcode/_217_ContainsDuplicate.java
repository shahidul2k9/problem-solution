
import java.util.HashMap;
import java.util.Map;

/**
 * @author Shahidul Islam
 * @date 1/23/2022
 **/
public class _217_ContainsDuplicate {
    public boolean containsDuplicate(int[] nums) {
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int x : nums) {
            if (countMap.containsKey(x)) {
                return true;
            } else {
                countMap.put(x, x);
            }
        }
        return false;

    }
}
