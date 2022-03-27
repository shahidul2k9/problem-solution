
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * @author Shahidul Islam
 * @date 2/26/2022
 **/
public class _480_SlidingWindowMedian {
    public double[] medianSlidingWindow(int[] nums, int k) {
        PriorityQueue<Integer> lowMaxPq = new PriorityQueue<>(Comparator.reverseOrder());
        PriorityQueue<Integer> highMinPq = new PriorityQueue<>();
        int n = nums.length;
        double[] medians = new double[n - k + 1];
        for (int i = 0; i < n; i++) {
            add(nums[i], lowMaxPq, highMinPq);
            if (i + 1 >= k) {
                medians[i - k + 1] = findMedian(lowMaxPq, highMinPq);
                int orphan = nums[i - k + 1];
                if (!lowMaxPq.remove(orphan))
                    highMinPq.remove(orphan);
                if (lowMaxPq.size() < highMinPq.size()) {
                    lowMaxPq.add(highMinPq.poll());
                }
            }
        }
        return medians;
    }

    private void add(int val, PriorityQueue<Integer> lowMaxPq, PriorityQueue<Integer> highMinPq) {
        lowMaxPq.add(val);
        highMinPq.add(lowMaxPq.poll());
        if (lowMaxPq.size() < highMinPq.size()) {
            lowMaxPq.add(highMinPq.poll());
        }
    }

    private double findMedian(PriorityQueue<Integer> lowMaxPq, PriorityQueue<Integer> highMinPq) {
        if (lowMaxPq.size() > highMinPq.size()) {
            return lowMaxPq.peek();
        } else {
            return lowMaxPq.peek() * 0.5 + highMinPq.peek() * 0.5;
        }
    }
}
