
/**
 * @author Shahidul Islam
 * @date 2/19/2022
 **/
public class _162_FindPeakElement {
    public int findPeakElement(int[] nums) {

        return binaryPeakSearch(0, nums.length - 1, nums);
    }

    private int binaryPeakSearch(int lo, int hi, int[] nums) {
        while (lo <= hi) {
            int midIndex = (lo + hi) / 2;
            int leftVal = midIndex - 1 >= 0 ? nums[midIndex - 1] : Integer.MIN_VALUE;
            int rightVal = midIndex + 1 <= hi ? nums[midIndex + 1] : Integer.MIN_VALUE;
            int midVal = nums[midIndex];

            if (leftVal < midVal && midVal > rightVal) {
                return midIndex;
            } else if (midVal < rightVal) {
                lo = midIndex + 1;
            } else {
                hi = midIndex - 1;
            }
        }
        return -lo;
    }
}
