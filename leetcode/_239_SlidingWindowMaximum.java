
import java.util.*;

/**
 * @author Shahidul Islam
 * @date 2/8/2022
 **/
public class _239_SlidingWindowMaximum {
    public int[] maxSlidingWindow(int[] nums, int k) {
        List<Integer> maxList = new ArrayList<>();
        TreeSet<Integer> runningSequence = new TreeSet<>();
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int n = nums[i];
            frequencyMap.put(n, frequencyMap.getOrDefault(n, 0) + 1);
            runningSequence.add(n);
            if (i + 1 >= k) {
                maxList.add(runningSequence.last());
                int orphan = nums[i - k + 1];
                Integer f = frequencyMap.get(orphan);
                if (f == 1) {
                    runningSequence.remove(orphan);
                }
                frequencyMap.put(orphan, f - 1);
            }
        }
        return maxList.stream()
                .mapToInt(Integer::intValue)
                .toArray();

    }
}
