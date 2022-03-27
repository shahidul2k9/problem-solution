
import java.util.Deque;
import java.util.concurrent.LinkedBlockingDeque;

/**
 * @author Shahidul Islam
 * @date 2/8/2022
 **/
public class _1438_LongestSubbarrayWithAbsLimit {
    public int longestSubarray(int[] nums, int limit) {
        int n = nums.length;
        int maxLength = 0;
        int left = -1;
        Deque<Integer> maxQueue = new LinkedBlockingDeque<>();
        Deque<Integer> minQueue = new LinkedBlockingDeque<>();
        for (int right = 0; right < n; right++) {
            int newVal = nums[right];
            while (!maxQueue.isEmpty() && nums[maxQueue.peekLast()] < newVal)
                maxQueue.pollLast();
            maxQueue.offer(right);

            while (!minQueue.isEmpty() && nums[minQueue.peekLast()] > newVal)
                minQueue.pollLast();
            minQueue.offer(right);

            while (Math.abs(newVal - nums[maxQueue.peek()]) > limit) {
                left = Math.max(maxQueue.pollFirst(), left);
            }

            while (Math.abs(newVal - nums[minQueue.peek()]) > limit) {
                left = Math.max(minQueue.pollFirst(), left);
            }


            //System.out.println(minQueue.peek() + "-" + nums[minQueue.peek()] + " " + maxQueue.peek() + "-" + nums[maxQueue.peek()]);

            maxLength = Math.max(maxLength, right - left);
        }
        return maxLength;

    }
}
