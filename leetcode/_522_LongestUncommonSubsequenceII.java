
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 1/28/2022
 **/
public class _522_LongestUncommonSubsequenceII {
    public int findLUSlength(String[] strs) {
        Arrays.sort(strs, (o1, o2) -> o1.length() - o2.length());
        int left = 0;
        int globBalLus = 0;
        while (left < strs.length) {
            int maxLus = strs[left].length();
            for (int i = 0; i < strs.length; i++) {
                if (left != i && isSubSequence(strs[left], strs[i])) {
                    maxLus = 0;
                    break;
                }
            }
            globBalLus = Math.max(maxLus, globBalLus);
            left++;
        }
        return globBalLus == 0 ? -1 : globBalLus;
    }

    private boolean isSubSequence(String s, String t) {
        if (s.length() > t.length()) {
            return false;
        }

        int sLeft,tLeft;
        sLeft = tLeft = 0;
        while (sLeft < s.length() && tLeft < t.length()){
            if (s.charAt(sLeft) == t.charAt(tLeft)){
                sLeft++;
            }
            tLeft++;
        }
        return sLeft >= s.length();
    }
}
