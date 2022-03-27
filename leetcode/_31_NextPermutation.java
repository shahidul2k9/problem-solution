
/**
 * @author Shahidul Islam
 * @date 2/2/2022
 **/
public class _31_NextPermutation {
    public void nextPermutation(int[] nums) {
        int i = nums.length - 1;
        while (i > 0 && nums[i - 1] >= nums[i]) {
            i--;
        }
        if (i > 0) {
            int j = nums.length - 1;
            while (j > 0 && nums[j] <= nums[i - 1]) j--;
            swap(nums, i - 1, j);
            reverse(nums, i, nums.length - 1);
        } else {
            reverse(nums, 0, nums.length - 1);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    private void reverse(int[] nums, int from, int to) {
        while (from < to) {
            int tmp = nums[to];
            nums[to] = nums[from];
            nums[from] = tmp;
            from++;
            to--;
        }
    }
}
