
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 * @author Shahidul Islam
 * @date 2/8/2022
 **/
public class _1871_JumpGameVII {
    public boolean canReach(String s, int minJump, int maxJump) {
        int n = s.length();
        int k = maxJump - minJump + 1;
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        for (int i = minJump; i < n; i++) {
            while (!q.isEmpty() && (q.peek() < i - maxJump || q.peek() + minJump >= n))
                q.poll();

            if (s.charAt(i) == '0' && !q.isEmpty()) {
                for (Integer left : q) {
                    if (left + minJump <= i) {
                        q.offer(i);
                        if (i == n - 1) {
                            return true;
                        }
                        break;
                    }
                }

            }
        }
        return false;
    }
}
