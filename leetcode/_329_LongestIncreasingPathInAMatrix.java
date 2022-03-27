
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 * @author Shahidul Islam
 * @date 2/19/2022
 **/
public class _329_LongestIncreasingPathInAMatrix {
    private static final int[] dx = new int[]{0, -1, 0, 1};
    private static final int[] dy = new int[]{1, 0, -1, 0};

    private static class Node {
        public Node(int r, int c, int d) {
            this.r = r;
            this.c = c;
            this.d = d;
        }

        public int r;
        public int c;
        public int d;
    }

    public int longestIncreasingPath(int[][] matrix) {
        Queue<Node> pq = new LinkedList<>();
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] d = new int[m][n];
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                pq.add(new Node(r, c, 1));
                d[r][c] = 1;
            }
        }
        while (!pq.isEmpty()) {
            Node u = pq.poll();
            for (int k = 0; k < dx.length; k++) {
                int nr = u.r + dx[k];
                int nc = u.c + dy[k];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[u.r][u.c] < matrix[nr][nc] && 1 + u.d > d[nr][nc]) {
                    d[nr][nc] = 1 + u.d ;
                    pq.offer(new Node(nr, nc, d[nr][nc]));
                }
            }
        }

        int maxD = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                maxD = Math.max(maxD, d[r][c]);
            }
        }
        return maxD;
    }
}
