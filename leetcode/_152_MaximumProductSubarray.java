
/**
 * @author Shahidul Islam
 * @date 2/6/2022
 **/
public class _152_MaximumProductSubarray {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int x;
        int y;
        int globalMaxProduct;
        x = y = globalMaxProduct = nums[0];
        for (int i = 1; i < n; i++) {
            int tmpX = Math.min(Math.min(x * nums[i], y * nums[i]), nums[i]);
            y = Math.max(Math.max(x * nums[i], y * nums[i]), nums[i]);
            globalMaxProduct = Math.max(globalMaxProduct, y);
            x = tmpX;
        }
        return globalMaxProduct;
    }
}
