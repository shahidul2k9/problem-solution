
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/3/2022
 **/
public class _1905_CountSubIslands {
    private static final int[] dx = new int[]{0, -1, 0, 1};
    private static final int[] dy = new int[]{1, 0, -1, 0};

    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int m = grid2.length;
        int n = grid2[0].length;
        boolean[][] visitedGrid = new boolean[m][n];
        Arrays.stream(visitedGrid)
                .forEach(row -> Arrays.fill(row, false));

        int subIsland = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (!visitedGrid[r][c] && grid2[r][c] == 1 ) {
                    subIsland += isSubIsland(m, n, grid1, grid2, r, c, visitedGrid)? 1 : 0;
                    //System.out.println(Arrays.deepToString(visitedGrid));
                }
            }
        }
        return subIsland;
    }

    private boolean isSubIsland(int m, int n, int[][] grid1, int[][] grid2, int r, int c, boolean[][] visitedGrid) {
        //System.out.println(r + " "  + c);
        visitedGrid[r][c] = true;
        boolean isSub = (grid1[r][c] == 1);
        for (int d = 0; d < dx.length; d++) {
            int nr = r + dx[d];
            int nc = c + dy[d];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visitedGrid[nr][nc] && grid2[nr][nc] == 1) {
                boolean sb =  isSubIsland(m, n, grid1, grid2, nr, nc, visitedGrid);
                isSub = isSub && sb;
            }
        }
        return isSub;
    }
}
