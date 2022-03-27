
import java.util.List;
import java.util.Map;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.function.Function;
import java.util.stream.Collectors;

/**
 * @author Shahidul Islam
 * @date 2/25/2022
 **/
public class _139_WordBreak {
    public boolean wordBreak(String s, List<String> wordDict) {
        Boolean[] dp = new Boolean[s.length()];
        AtomicBoolean trueVal = new AtomicBoolean(true);
        Map<String, Boolean> wordMap = wordDict.stream()
                .collect(Collectors.toMap(Function.identity(), key -> trueVal.get()));
        return isBreakable(0, s, dp, wordMap);
    }

    private Boolean isBreakable(int start, String s, Boolean[] dp, Map<String, Boolean> wordMap) {

        if (start == s.length())
            return true;
        else if (dp[start] != null)
            return dp[start];

        for (int i = start; i < s.length(); i++) {
            String word = s.substring(start, i + 1);
            if (wordMap.containsKey(word) && isBreakable(i+1, s, dp, wordMap)) {
               return dp[start] = true;
            }
        }
        return dp[start] = false;


    }
}
