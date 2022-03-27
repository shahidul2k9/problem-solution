
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

/**
 * @author Shahidul Islam
 * @date 2/13/2022
 **/
public class _318_MaximumProductOfWordLengths {
    public int maxProduct(String[] words) {
        int n = words.length;
        List<Map<Character, Integer>> fcList = new LinkedList<>();
        for (String word : words) {
            Map<Character, Integer> m = new HashMap<>();
            for (int i = 0; i < word.length(); i++) {
                m.put(word.charAt(i), m.getOrDefault(word.charAt(i), 0) + 1);
            }
            fcList.add(m);
        }
        int maxProd = 0;
        for (int w1 = 0; w1 < n; w1++) {
            for (int w2 = w1 + 1; w2 < n; w2++) {
                Map<Character, Integer> w1CharMap = fcList.get(w1);
                String w2Word = words[w2];
                int i;
                for (i = 0; i < w2Word.length(); i++) {
                    if (w1CharMap.containsKey(w2Word.charAt(i))) {
                        break;
                    }
                }
                if (i == w2Word.length()) {
                    maxProd = Math.max(words[w1].length() * words[w2].length(), maxProd);
                }

            }
        }
        return maxProd;
    }
}
