
/**
 * @author Shahidul Islam
 * @date 1/28/2022
 **/
public class _132_PalindromePartitioningII {
    public int minCut(String s) {
        int n = s.length();
        int[] mc = new int[n];
        boolean[][] pl = new boolean[n][n];

        for (int l = 1; l <= n; l++) {
            for (int b = 0; b < n; b++) {
                int e = b + l - 1;
                if (e >= n)break;

                boolean isOutsideCharPalindrome = s.charAt(b) == s.charAt(e);
                if (e - b < 2) {
                    pl[b][e] = isOutsideCharPalindrome;
                } else {
                    pl[b][e] = isOutsideCharPalindrome && pl[b + 1][e - 1];
                }
            }

        }
        for (int i = 0; i < n; i++) {
            mc[i] = (pl[0][i]) ? 0 : i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j > 0; j--) {
                if (pl[j][i]) {
                    mc[i] = Math.min(mc[i], 1 + mc[j - 1]);
                }
            }
        }
        return mc[n - 1];

    }
}
