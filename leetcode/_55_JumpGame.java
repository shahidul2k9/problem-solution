
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 1/31/2022
 **/
public class _55_JumpGame {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        boolean[] jumped = new boolean[n];
        Arrays.fill(jumped,false);
        jumped[0] = true;


        for (int i = 0; i < n;i++){
            if (jumped[i] ){
                for (int j = 1;  j <= nums[i] && i + j < n;j++){
                    jumped[i+j] = true;
                }

            }
        }
        return jumped[n-1];
    }
}
