
import java.util.*;

/**
 * @author Shahidul Islam
 * @date 2/17/2022
 **/
public class _347_TopKFrequentElements {
    private static class Node implements Comparable<Node> {
        public Node(int v, int f) {
            this.v = v;
            this.f = f;
        }

        public int v;
        public int f;

        @Override
        public int compareTo(Node o) {
            return -(f - o.f);
        }
    }

    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> fm = new HashMap<>();
        for (int key : nums) {
            fm.put(key, fm.getOrDefault(key, 0) + 1);
        }
        List<Integer> frequentList = new ArrayList<>();
        PriorityQueue<Node> pq = new PriorityQueue<>();
        for (int key : fm.keySet()) {
            pq.add(new Node(key, fm.get(key)));
        }
        while (!pq.isEmpty() && frequentList.size() < k) {
            frequentList.add(pq.poll().v);
        }
        return frequentList.stream()
                .mapToInt(Integer::intValue)
                .toArray();

    }
}
