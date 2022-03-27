
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.function.Function;
import java.util.stream.Collectors;

/**
 * @author Shahidul Islam
 * @date 2/25/2022
 **/
public class _140_WordBreakII {
    public List<String> wordBreak(String s, List<String> wordDict) {
        AtomicBoolean trueVal = new AtomicBoolean(true);
        Map<String, Boolean> wordMap = wordDict.stream()
                .collect(Collectors.toMap(Function.identity(), val -> trueVal.get()));

        List<List<String>> dp = new ArrayList<>(s.length() + 1);

        for (int i = 0; i < s.length() + 1; i++)
            dp.add(null);


        return spread(0, s, dp, wordMap);
    }

    private List<String> spread(int start, String s, List<List<String>> dp, Map<String, Boolean> wordMap) {

        if (dp.get(start) != null) {
            return dp.get(start);
        } else {
            List<String> sentenceList = new ArrayList<>();
            for (int i = start; i < s.length(); i++) {
                String w = s.substring(start, i + 1);
                if (wordMap.containsKey(w)) {
                    if (i + 1 == s.length()) {
                        sentenceList.add(w);
                    } else {
                        List<String> endingList = spread(i + 1, s, dp, wordMap);
                        sentenceList.addAll(endingList.stream()
                                .map(val -> w + " " + val)
                                .collect(Collectors.toList()));
                    }

                }
            }
            dp.set(start, sentenceList);
            return sentenceList;
        }
    }
}
