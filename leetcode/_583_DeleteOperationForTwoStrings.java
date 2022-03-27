
/**
 * @author Shahidul Islam
 * @date 1/30/2022
 **/
public class _583_DeleteOperationForTwoStrings {
    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        int[][] d = new int[m + 1][n + 1];
        for (int r = 0; r <= m; r++)
            d[r][0] = r;
        for (int c = 0; c <= n; c++)
            d[0][c] = c;
        for (int r = 1; r <= m; r++) {
            for (int c = 1; c <= n; c++) {
                if (word1.charAt(r - 1) == word2.charAt(c - 1)) {
                    d[r][c] = d[r - 1][c - 1];
                } else {
                    d[r][c] = 1 + Math.min(d[r - 1][c], d[r][c - 1]);

                }
            }
        }
        return d[m][n];
    }
}
