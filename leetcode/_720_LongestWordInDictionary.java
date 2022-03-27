
import java.util.*;

/**
 * @author Shahidul Islam
 * @date 2/16/2022
 **/
public class _720_LongestWordInDictionary {
    public String longestWord(String[] words) {
        Set<String> wordSet = new TreeSet<>(Arrays.asList(words));

        int ml = 0;
        String longestWord = "";
        for (String word : wordSet) {
            if (word.length() > ml) {
                int cn = 0;
                while (cn < word.length() && wordSet.contains(word.substring(0, cn + 1)))
                    cn++;
                if (cn == word.length()) {
                    ml = cn;
                    longestWord = word;
                }
            }
        }
        return longestWord;

    }
}
