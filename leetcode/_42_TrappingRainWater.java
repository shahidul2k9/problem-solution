
/**
 * @author Shahidul Islam
 * @date 1/29/2022
 **/
public class _42_TrappingRainWater {
    public int trap(int[] height) {
        int n = height.length;
        int[] leftPillar = new int[n];
        int[] rightPillar = new int[n];
        for (int i = 0; i < n; i++) {
            int b = n - i - 1;
            if (i == 0) {
                leftPillar[i] = rightPillar[b] = 0;
            }else {
                leftPillar[i] = Math.max(leftPillar[i - 1], height[i - 1]);
                rightPillar[b] = Math.max(rightPillar[b + 1], height[b + 1]);
            }
        }
        int totalWater = 0;
        for (int i = 0; i < n; i++) {
            int h = Math.min(leftPillar[i], rightPillar[i]);
            int water = h - height[i];
            totalWater += (water > 0 ? water : 0);
        }
        return totalWater;

    }
}
