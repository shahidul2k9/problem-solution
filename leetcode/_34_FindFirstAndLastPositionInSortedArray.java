
/**
 * @author Shahidul Islam
 * @date 1/31/2022
 **/
public class _34_FindFirstAndLastPositionInSortedArray {
    public int[] searchRange(int[] nums, int target) {
        int lowerBound = lowerBound(nums, target);
        int uppBound = upperBound(nums, target);
        if (uppBound == lowerBound) {
            return new int[]{-1, -1};
        } else {
            return new int[]{lowerBound, uppBound - 1};
        }

    }

    private int lowerBound(int[] nums, int target) {
        int low = 0;
        int high = nums.length;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    private int upperBound(int[] nums, int target) {
        int low = 0;
        int high = nums.length;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}