
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/5/2022
 **/
public class _45_JumpGameII {
    public int jump(int[] nums) {
        int n = nums.length;
        int[] jp = new int[n];
        int inf = 1000000;
        Arrays.fill(jp, inf);
        jp[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            if (jp[i] != inf) {
                for (int k = 1; k <= nums[i] && i + k < n; k++) {
                    jp[i + k] = Math.min(jp[i + k], jp[i] + 1);
                }
            }
        }
        return jp[n - 1];

    }
}
