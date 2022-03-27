
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/4/2022
 **/
public class _32_LongestValidParentheses {
    public int longestValidParentheses(String s) {
        int n = s.length();
        int[] lvp = new int[n];
        Arrays.fill(lvp, 0);
        int max = 0;
        if (n != 0) {
            lvp[0] = 0;
            for (int i = 1; i < n; i++) {
                if (s.charAt(i) == ')') {
                    if (s.charAt(i - 1) == '(') {
                        lvp[i] = 2 + (i - 2 >= 0 ? lvp[i - 2] : 0);
                    } else if (i - 1 - lvp[i - 1] >= 0 && s.charAt(i - 1 - lvp[i - 1]) == '(') {
                        lvp[i] = 2 + lvp[i - 1] + (i - 1 - lvp[i - 1] - 1 >= 0 ? lvp[i - 1 - lvp[i - 1] - 1] : 0);
                    }
                }
                max = Math.max(max, lvp[i]);
            }

        }
        return max;

    }
}
