
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

/**
 * @author Shahidul Islam
 * @date 2/5/2022
 **/
public class _1306_JumpGameIII {
    public boolean canReach(int[] arr, int start) {
        Queue<Integer> q = new LinkedList<>();
        int n = arr.length;
        Boolean[] dp = new Boolean[n];
        Arrays.fill(dp, null);
        q.add(start);
        dp[start] = true;
        while (!q.isEmpty()){
            Integer i = q.poll();
            if (arr[i] == 0)
                return true;

            int right = i + arr[i];
            if (right < n && dp[right] == null){
                q.add(right);
                dp[right] = true;
            }
            int left = i - arr[i];
            if (left >= 0 && dp[left] == null){
                q.add(left);
                dp[left] = true;
            }
        }
        return false;
    }
}
