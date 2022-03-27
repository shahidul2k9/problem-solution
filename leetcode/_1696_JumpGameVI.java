
import java.util.PriorityQueue;

/**
 * @author Shahidul Islam
 * @date 2/8/2022
 **/
public class _1696_JumpGameVI {
    private static class Node {
        public Node(int v, int w) {
            this.v = v;
            this.w = w;
        }

        public int v;
        public int w;
    }

    public int maxResult(int[] nums, int k) {
        PriorityQueue<Node> pq = new PriorityQueue<>((a,b) -> b.w-a.w);
        Node lastNode = new Node(0, nums[0]);
        pq.offer(lastNode);
        for (int i = 1; i < nums.length; i++) {
            while (pq.peek().v < i - k) {
                pq.poll();
            }
            lastNode = new Node(i, pq.peek().w + nums[i]);
            pq.offer(lastNode);
        }
        return lastNode.w;


    }
}
