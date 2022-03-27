
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/1/2022
 **/
public class _36_ValidSudoku {
    public boolean isValidSudoku(char[][] board) {
        int n = board.length;
        int digits = 10;
        int[][] rowSum = new int[n][digits];
        int[][] colSum = new int[n][digits];
        int[][][] littleSquare = new int[3][3][digits];

        for (int[] row :
                rowSum) {
            Arrays.fill(row, 0);
        }
        for (int[] col : colSum) {
            Arrays.fill(col, 0);
        }
        Arrays.stream(littleSquare)
                .forEach(row -> Arrays.stream(row).forEach(col -> Arrays.fill(col, 0)));
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                char ch = board[r][c];
                if (ch != '.') {
                    int d = ch - '0';
                    rowSum[r][d]++;
                    colSum[c][d]++;
                    littleSquare[r / 3][c / 3][d]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int d = 0; d < digits; d++)
                if (rowSum[i][d] > 1 || colSum[i][d] > 1) {
                    return false;
                }
        }
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                for (int d = 0; d < digits; d++) {
                    if (littleSquare[r][c][d] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
