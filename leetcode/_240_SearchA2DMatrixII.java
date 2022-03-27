
/**
 * @author Shahidul Islam
 * @date 2/5/2022
 **/
public class _240_SearchA2DMatrixII {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix[0].length;
        return searchZigzag(matrix, m, n, target, 0, n - 1);
    }

    private boolean searchZigzag(int[][] matrix, int m, int n, int target, int r, int c) {
        if (r >= m || c < 0) {
            return false;
        } else if (matrix[r][c] == target) {
            return true;
        } else if (matrix[r][c] > target) {
            return searchZigzag(matrix, m, n, target, r, c - 1);
        } else return searchZigzag(matrix, m, n, target, r + 1, c);

    }

}
