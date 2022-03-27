
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author Shahidul Islam
 * @date 2/12/2022
 **/
public class _17_LetterCombinationsOfAPhoneNumber {
    private static Map<Character, String> charMap = new HashMap<>();

    static {
        charMap.put('2', "abc");
        charMap.put('3', "def");
        charMap.put('4', "ghi");
        charMap.put('5', "jkl");
        charMap.put('6', "mno");
        charMap.put('7', "pqrs");
        charMap.put('8', "tuv");
        charMap.put('9', "wxyz");
    }

    public List<String> letterCombinations(String digits) {
        List<String> combinationList = new ArrayList<>();
        generationCombination(digits, 0, new StringBuilder(), combinationList);
        return combinationList;

    }

    private void generationCombination(String digits, int pos, StringBuilder sequence, List<String> combinationList) {
        if (pos == digits.length()) {
            if (sequence.length() > 0)
                combinationList.add(sequence.toString());
        } else {
            String alphabet = charMap.get(digits.charAt(pos));
            for (int i = 0; i < alphabet.length(); i++) {
                sequence.append(alphabet.charAt(i));
                generationCombination(digits, pos + 1, sequence, combinationList);
                sequence.deleteCharAt(sequence.length() - 1);
            }
        }
    }

}
