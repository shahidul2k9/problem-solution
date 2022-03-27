
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/7/2022
 **/
public class _76_MinimumWindowSubstring {
    private static final int A = 2*26 + 6;
    public String minWindow(String s, String t) {
        int optLeft, optRight, l;
        int[] tf = new int[A];
        int[] cf = new int[A];
        Arrays.fill(tf, 0);
        Arrays.fill(cf, 0);

        for (int i = 0; i < t.length(); i++) {
            tf[t.charAt(i) - 'A']++;
        }

        l = 0;
        optLeft = 0;
        optRight = s.length() * 2;
        for (int r = 0; r < s.length(); r++) {

            int pos = s.charAt(r) - 'A';
            int leftPos = s.charAt(l) - 'A';
            cf[pos]++;

            while ((tf[leftPos] == 0 || cf[leftPos] - 1 >= tf[leftPos]) && l < r) {
                cf[leftPos]--;
                l++;
                leftPos = s.charAt(l) - 'A';
            }
            if (isMatchWindow(tf, cf) && (r - l) < (optRight - optLeft)) {
                optLeft = l;
                optRight = r;
            }
        }
        return optRight - optLeft < s.length() ? s.substring(optLeft, optRight + 1) : "";

    }


    private boolean isMatchWindow(int[] tf, int[] cf) {
        for (int i = 0; i < A; i++) {
            if (tf[i] != 0 && cf[i] < tf[i])
                return false;
        }
        return true;
    }
}
