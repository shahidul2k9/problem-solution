
import java.util.HashMap;
import java.util.Map;

/**
 * @author Shahidul Islam
 * @date 2/17/2022
 **/
public class _567_PermutationInString {
    public boolean checkInclusion(String s1, String s2) {
        int N = s2.length();
        int M = s1.length();
        Map<Character, Integer> fm;
        for (int i = 0; i < N - M + 1; i++) {
            fm = getFrequencyMap(s1);
            int mt = 0;
            for (int k = 0; k < M; k++) {
                char ch = s2.charAt(i + k);
                Integer f = fm.getOrDefault(ch, 0);
                if (f > 0) {
                    fm.put(ch, f - 1);
                    mt++;
                } else
                    break;
            }
            if (mt == M)
                return true;
        }
        return false;
    }

    private Map<Character, Integer> getFrequencyMap(String s) {
        Map<Character, Integer> fm = new HashMap<>();
        for (Character ch : s.toCharArray()) {
            fm.put(ch, fm.getOrDefault(ch, 0) + 1);
        }
        return fm;
    }
}
