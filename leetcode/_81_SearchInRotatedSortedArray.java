
/**
 * @author Shahidul Islam
 * @date 1/30/2022
 **/
public class _81_SearchInRotatedSortedArray {
    public boolean search(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;
        while (low <= high) {
            int mid = low + (high - low >> 1);
            if (nums[mid] == target) {
                return true;
            } else if (nums[low] == nums[mid]) {
                low++;
            } else if (nums[low] < nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
}
