
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * @author Shahidul Islam
 * @date 2/3/2022
 **/
public class _778_SwimInRisingWater {
    private static final int[] dx = new int[]{0, -1, 0, 1};
    private static final int[] dy = new int[]{1, 0, -1, 0};

    private static class Node {
        public Node(int r, int c, int v, int d) {
            this.d = d;
            this.v = v;
            this.r = r;
            this.c = c;
        }

        public int d;
        public int v;
        public int r;
        public int c;
    }

    public int swimInWater(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[] d = new int[m * n];
        Arrays.fill(d, Integer.MAX_VALUE);

        PriorityQueue<Node> pq = new PriorityQueue<>(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.d - o2.d;
            }
        });
        int sd = grid[0][0];
        d[0] = sd;
        Node start = new Node(0, 0, 0, sd);
        pq.add(start);
        while (!pq.isEmpty()) {
            Node from = pq.poll();
            for (int i = 0; i < dx.length; i++) {
                int nr = from.r + dx[i];
                int nc = from.c + dy[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int nd = Math.max(from.d, grid[nr][nc]);
                    Node to = new Node(nr, nc, nr * n + nc, nd);
                    if (to.d < d[to.v]) {
                        d[to.v] = to.d;
                        pq.add(to);
                    }
                }
            }
        }
        return d[m * n - 1];
    }
}
