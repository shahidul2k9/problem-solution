
/**
 * @author Shahidul Islam
 * @date 2/11/2022
 **/
public class _73_SetMatrixZeroes {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int r0 = 1;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    if (r == 0) {
                        r0 = 0;
                    } else {
                        matrix[r][0] = 0;
                    }
                }
            }
        }
        for (int r = 1; r < m; r++) {
            if (matrix[r][0] == 0) {
                for (int c = 1; c < n; c++) {
                    matrix[r][c] = 0;
                }
            }
        }

        for (int c = 0; c < n; c++) {
            if (matrix[0][c] == 0) {
                for (int r = 1; r < m; r++) {
                    matrix[r][c] = 0;
                }
            }
        }

        if (r0 == 0) {
            for (int c = 0; c < n; c++) {
                matrix[0][c] = 0;
            }
        }
    }
}

