
import java.util.Arrays;

class _26_RemoveDuplicateFromSortedArray {
    public int removeDuplicates(int[] nums) {
        int n;
        if (nums.length > 0){
            n = 1;
            int val;
            for (int i = 1; i < nums.length;i++){
                val = nums[i];
                if (Arrays.binarySearch(nums, 0, n, val) < 0){
                    nums[n++] = val;
                }
            }
        }else {
            n = 0;
        }
        return n;
    }
}