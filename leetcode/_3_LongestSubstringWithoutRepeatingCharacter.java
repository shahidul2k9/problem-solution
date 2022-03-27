
import java.util.HashMap;
import java.util.Map;

class _3_LongestSubstringWithoutRepeatingCharacter {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> charPosition = new HashMap<>();
        int begin, ML;
        begin = 0;
        ML = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (charPosition.containsKey(ch) && begin <= charPosition.get(ch)) {
                ML = Math.max(ML, i - begin);
                begin = charPosition.get(ch) + 1;
            }else {
                ML = Math.max(ML, i - begin + 1);
            }
            charPosition.put(ch, i);
        }
        return ML;

    }
}
