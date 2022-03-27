
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * @author Shahidul Islam
 * @date 2/26/2022
 **/
public class _1094_CarPooling {
    public boolean carPooling(int[][] trips, int capacity) {
        Arrays.sort(trips, Comparator.comparingInt(t -> t[1]));
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparing(t -> t[2]));
        for (int i = 0; i < trips.length; i++) {
            int[] t = trips[i];
            while (!pq.isEmpty() && pq.peek()[2] <= t[1]) {
                capacity += pq.peek()[0];
                pq.poll();
            }
            if (capacity - t[0] >= 0) {
                capacity -= t[0];
                pq.offer(t);
            } else {
                return false;
            }
        }
        return true;
    }
}
