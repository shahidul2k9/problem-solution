
import java.util.TreeSet;

/**
 * @author Shahidul Islam
 * @date 2/8/2022
 **/
public class _220_ContainsDuplicateIII {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if (k == 0)
            return false;
        TreeSet<Long> set = new TreeSet<>();
        for (int i = 0; i < nums.length; i++) {
            long x = nums[i];
            Long ceil = set.ceiling(x);
            if (ceil != null && ceil - x <= t) {
                return true;
            }
            Long floor = set.floor(x);
            if (floor != null && x - floor <= t) {
                return true;
            }
            if (i >= k) {
                set.remove((long) nums[i - k]);
            }
            set.add(x);
        }
        return false;

    }
}
