
import java.util.HashSet;
import java.util.Set;

/**
 * @author Shahidul Islam
 * @date 2/5/2022
 **/
public class _41_FirstMissingPositive {
    public int firstMissingPositive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        set.add(0);
        for (int key :
                nums) {
            set.add(key);
        }
        int sp = Integer.MAX_VALUE;
        for (int key : set) {
            for (int f : new int[]{-1, 1}) {
                int smallerKey = key + f;
                if (smallerKey > 0 && smallerKey < sp && !set.contains(smallerKey)) {
                    sp = smallerKey;
                }
            }

        }
        return sp;
    }
}
