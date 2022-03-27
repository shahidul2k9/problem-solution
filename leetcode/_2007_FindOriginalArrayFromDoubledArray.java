
import java.util.*;

/**
 * @author Shahidul Islam
 * @date 2/24/2022
 **/
public class _2007_FindOriginalArrayFromDoubledArray {
    public int[] findOriginalArray(int[] changed) {
        int n = changed.length;
        int[] nai = {};
        if (n % 2 != 0) {
            return nai;
        }
        Map<Integer, Integer> frequencyMap = new TreeMap<>();
        Arrays.stream(changed)
                .forEach(key -> {
                    frequencyMap.put(key, frequencyMap.getOrDefault(key, 0) + 1);
                });

        List<Integer> originalList = new ArrayList<>();
        for (int key : frequencyMap.keySet()) {
            while (true) {
                int f = frequencyMap.getOrDefault(key, 0);
                int twoF = frequencyMap.getOrDefault(2 * key, 0);
                if (f <= 0)
                    break;
                else {
                    if (key == 0) {
                        if (f >= 2) {
                            originalList.add(key);
                            frequencyMap.put(key, f - 2);
                        } else {
                            return nai;
                        }
                    } else if (twoF >= 1) {
                        frequencyMap.put(key, f - 1);
                        frequencyMap.put(key * 2, twoF - 1);
                        originalList.add(key);
                    } else {
                        return nai;
                    }
                }
            }
        }
        return originalList.stream()
                .mapToInt(Integer::intValue)
                .toArray();

    }
}
