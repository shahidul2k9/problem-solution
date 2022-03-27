
/**
 * @author Shahidul Islam
 * @date 2/5/2022
 **/
public class _74_SearchA2DMatrix {
    public boolean searchMatrix(int[][] matrix, int target) {
        return binarySearch(matrix, target) >= 0;
    }

    private int binarySearch(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix[0].length;
        int low = 0;
        int high = m * n - 1;
        while (low <= high) {
            int midIndex = (low + high) / 2;
            int r = midIndex / n;
            int c = midIndex % n;
            int midValue = matrix[r][c];
            if (midValue == target) {
                return midIndex;
            } else if (target < midValue) {
                high = midIndex - 1;
            } else {
                low = midIndex + 1;
            }
        }
        return -1;
    }
}
