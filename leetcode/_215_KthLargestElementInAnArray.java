
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * @author Shahidul Islam
 * @date 2/13/2022
 **/
public class _215_KthLargestElementInAnArray {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for (int num : nums) {
            pq.offer(num);
        }
        for (int i = 0; i < k - 1; i++)
            pq.poll();
        return pq.peek();

    }
}
