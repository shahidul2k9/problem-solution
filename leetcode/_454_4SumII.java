
import java.util.HashMap;
import java.util.Map;

/**
 * @author Shahidul Islam
 * @date 1/29/2022
 **/
public class _454_4SumII {
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {

        int tupleCount = 0;
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int a : nums1) {
            for (int b : nums2) {
                int key = a + b;
                countMap.put(key, countMap.getOrDefault(key, 0) + 1);
            }
        }
        for (int c : nums3) {
            for (int d : nums4) {
                int key = -(c + d);
                tupleCount += countMap.getOrDefault(key, 0);
            }
        }

        return tupleCount;
    }
}
