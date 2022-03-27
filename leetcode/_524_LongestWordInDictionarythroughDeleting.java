
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 2/16/2022
 **/
public class _524_LongestWordInDictionarythroughDeleting {
    public String findLongestWord(String s, List<String> dictionary) {
        dictionary.sort((a, b) -> {
            if (a.length() != b.length())
                return -(a.length() - b.length());
            else
                return a.compareTo(b);
        });
        for (String word : dictionary) {
            if (isSubSequence(s, word))
                return word;
        }
        return "";
    }

    private boolean isSubSequence(String a, String b) {
        int bIndex = 0;
        if (a.length() < b.length())
            return false;
        for (int i = 0; i < a.length() && bIndex < b.length(); i++) {
            if (a.charAt(i) == b.charAt(bIndex))
                bIndex++;
        }
        return bIndex == b.length();
    }
}
