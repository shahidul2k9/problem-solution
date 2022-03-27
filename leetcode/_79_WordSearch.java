
/**
 * @author Shahidul Islam
 * @date 2/11/2022
 **/
public class _79_WordSearch {
    private static final int[] dx = new int[]{0, -1, 0, 1};
    private static final int[] dy = new int[]{1, 0, -1, 0};

    public boolean exist(char[][] board, String word) {

        int m = board.length;
        int n = board[0].length;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (matchWord(board, m, n, r, c, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean matchWord(char[][] board, int m, int n, int x, int y, String word, int pos) {

        if (word.charAt(pos) == board[x][y]) {
            if (pos + 1 == word.length()) {
                return true;
            } else {
                char ch = board[x][y];
                board[x][y] = '*';
                for (int d = 0; d < dx.length; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] != '*') {
                        if (matchWord(board, m, n, nx, ny, word, pos + 1)) {
                            //board[x][y] = ch;
                            return true;
                        }
                    }
                }
                board[x][y] = ch;
                return false;
            }

        } else
            return false;
    }
}
