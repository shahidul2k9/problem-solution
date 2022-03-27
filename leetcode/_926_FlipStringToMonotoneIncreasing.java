
/**
 * @author Shahidul Islam
 * @date 2/24/2022
 **/
public class _926_FlipStringToMonotoneIncreasing {
    public int minFlipsMonoIncr(String s) {
        int n = s.length();
        int[] ps = new int[n];
        for (int i = 0; i < n; i++) {
            int c = s.charAt(i) - '0';
            if (i == 0) {
                ps[i] = c;
            } else {
                ps[i] = c + ps[i - 1];
            }
        }

        int mx = Integer.MAX_VALUE;
        for (int i = 0; i <= n; i++) {
            int leftOnes = i == 0 ? 0 : ps[i - 1];
            int rightZeros = (i == n ? 0 : (n - i) - (ps[n - 1] - leftOnes));
            mx = Math.min(leftOnes + rightZeros, mx);
        }
        return mx;

    }
}
