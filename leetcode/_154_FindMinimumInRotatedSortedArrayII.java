
/**
 * @author Shahidul Islam
 * @date 1/31/2022
 **/
public class _154_FindMinimumInRotatedSortedArrayII {
    public int findMin(int[] nums) {
        int minValue = nums[0];
        int low = 0;
        int high = nums.length - 1;
        while (low <= high) {
            int mid = low + (high - low >> 1);
            minValue = Math.min(minValue, nums[mid]);
            if (nums[low] == nums[mid]) {
                minValue = Math.min(minValue, nums[low]);
                low++;
            } else if (nums[low] < nums[mid]) {
                minValue = Math.min(minValue, nums[low]);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return minValue;

    }
}
