
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * @author Shahidul Islam
 * @date 2/26/2022
 **/
public class _295_FindMedianFromDataStream {
    PriorityQueue<Integer> lowMaxPq = new PriorityQueue<>(Comparator.reverseOrder());
    PriorityQueue<Integer> highMinPq = new PriorityQueue<>();


    public _295_FindMedianFromDataStream() {

    }

    public void addNum(int num) {
        lowMaxPq.add(num);
        highMinPq.add(lowMaxPq.poll());
        if (lowMaxPq.size() < highMinPq.size()) {
            lowMaxPq.add(highMinPq.poll());
        }
    }

    public double findMedian() {
        if (lowMaxPq.size() > highMinPq.size())
            return lowMaxPq.peek();
        else
            return lowMaxPq.peek() * 0.5 + highMinPq.peek() * 0.5;

    }
}
