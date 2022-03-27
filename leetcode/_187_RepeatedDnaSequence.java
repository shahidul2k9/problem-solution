
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author Shahidul Islam
 * @date 1/23/2022
 **/
public class _187_RepeatedDnaSequence {
    public List<String> findRepeatedDnaSequences(String s) {
        Map<String, Integer> occurrenceCountMap = new HashMap<>();
        for (int i = 0; i + 10 <= s.length(); i++) {
            String stride = s.substring(i, i + 10);
            if (occurrenceCountMap.containsKey(stride)) {
                occurrenceCountMap.put(stride, occurrenceCountMap.get(stride) + 1);
            } else {
                occurrenceCountMap.put(stride, 1);
            }
        }
        List<String> occurrenceList = new ArrayList<>(occurrenceCountMap.size());
        for (String key : occurrenceCountMap.keySet()) {
            if (occurrenceCountMap.get(key) > 1) {
                occurrenceList.add(key);
            }
        }
        return occurrenceList;

    }
}
