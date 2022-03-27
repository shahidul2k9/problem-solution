
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 1/30/2022
 **/
public class _807_MaxIncreaseToKeepCitySkyline {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int n = grid.length;
        int[] rowMax = new int[n];
        int[] colMax = new int[n];
        Arrays.fill(rowMax, 0);
        Arrays.fill(colMax, 0);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                rowMax[r] = Math.max(rowMax[r], grid[r][c]);
                colMax[c] = Math.max(colMax[c], grid[r][c]);
            }
        }

        int maxTotal = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                maxTotal += Math.min(rowMax[r], colMax[c]) - grid[r][c];
            }
        }
        return maxTotal;

    }
}
