
import java.util.HashSet;
import java.util.Set;

/**
 * @author Shahidul Islam
 * @date 2/11/2022
 **/
public class _128_LongestConsecutiveSequence {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int key : nums) {
            set.add(key);
        }
        int maxCount = 0;
        for (int key : nums) {
            if (!set.contains(key - 1)) {
                int cnt = 0;
                while (set.contains(key)) {
                    cnt++;
                    key = key + 1;
                }
                maxCount = Math.max(cnt, maxCount);
            }
        }

        return maxCount;
    }
}
