
/**
 * @author Shahidul Islam
 * @date 1/26/2022
 **/
public class _238_ProductOfArrayExceptSelf {
    public int[] productExceptSelf(int[] nums) {
        int length = nums.length;
        int[] product = new int[length];
        product[length - 1] = nums[length - 1];
        for (int i = length-2; i >= 0; i--) {
            product[i] = product[i + 1] * nums[i];
        }
        int leftSuffixProduct = 1;
        for (int i = 0; i < length; i++) {
            product[i] = leftSuffixProduct * (i + 1 >= length ? 1 : product[i + 1]);
            leftSuffixProduct *= nums[i];
        }
        return product;
    }
}
