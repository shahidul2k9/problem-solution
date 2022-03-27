
import java.util.Arrays;

class _35_SearchInsertionPosition {
    public int searchInsert(int[] nums, int target) {
        int pos = Arrays.binarySearch(nums, target);
        return Math.abs(pos >= 0 ? pos : pos + 1);
    }
}