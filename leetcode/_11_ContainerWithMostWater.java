
/**
 * @author Shahidul Islam
 * @date 1/29/2022
 **/
public class _11_ContainerWithMostWater {
    public int maxArea(int[] height) {
        int left, right, leftHeight, rightHeight;
        int n = height.length;
        left = 0;
        right = n - 1;

        int maxWater = 0;
        while (left < right){
            leftHeight = height[left];
            rightHeight = height[right];
            int water = Math.min(leftHeight, rightHeight) * (right-left);
            maxWater = Math.max(maxWater, water);
            if (leftHeight < rightHeight){
                left++;
            }else {
                right--;
            }
        }
        return maxWater;
    }
}
