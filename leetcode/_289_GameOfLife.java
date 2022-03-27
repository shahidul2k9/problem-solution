
/**
 * @author Shahidul Islam
 * @date 2/11/2022
 **/
public class _289_GameOfLife {
    private static int[] dx = new int[]{0, -1, -1, -1, 0, 1, 1, 1};
    private static int[] dy = new int[]{1, 1, 0, -1, -1, -1, 0, 1};

    public void gameOfLife(int[][] board) {
        int m = board.length;
        int n = board[0].length;
        int[][] org = new int[m][n];
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                org[r][c] = board[r][c];
            }
        }
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                int oneCount = 0;
                for (int z = 0; z < dx.length; z++) {
                    if (r + dx[z] >= 0 && r + dx[z] < m && c + dy[z] >= 0 && c + dy[z] < n) {
                        int val = org[r + dx[z]][c + dy[z]];
                        oneCount += val;
                    }
                }
               // System.out.println(r + " " + c + " " + zeroCount + " " + oneCount);
                if (org[r][c] == 1) {
                    if (oneCount < 2 || oneCount > 3) {
                        board[r][c] = 0;
                    }
                } else {
                    if (oneCount == 3)
                        board[r][c] = 1;
                }
            }

        }
    }
}
