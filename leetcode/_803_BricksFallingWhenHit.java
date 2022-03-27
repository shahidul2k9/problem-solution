
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/3/2022
 **/
public class _803_BricksFallingWhenHit {
    private static final int[] dx = new int[]{0, -1, 0, 1};
    private static final int[] dy = new int[]{1, 0, -1, 0};

    public int[] hitBricks(int[][] grid, int[][] hits) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] ng = new int[m][n];
        int V = m * n;
        int[] sb = new int[hits.length];
        int[] flippedBrickAmongFallendBrick = new int[hits.length];
        int[] p = new int[V + 1];
        int[] rank = new int[V + 1];
        for (int i = 0; i <= V; i++) {
            p[i] = i;
            rank[i] = 1;
        }
        for (int r = 0; r < m; r++) {
            System.arraycopy(grid[r], 0, ng[r], 0, n);
        }

        for (int h = 0; h < hits.length; h++) {
            int r = hits[h][0];
            int c = hits[h][1];
            ng[r][c] = 0;
        }

        int totalBrick = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                totalBrick += ng[r][c];
                if (ng[r][c] == 1) {
                  /*  if (r == 0) {
                        union(p, rank, r * n + c, V);
                    }*/
                    mergeAdjacentBrick(ng, m, n, r, c, p, rank, V);
                }
            }
        }


        Arrays.fill(flippedBrickAmongFallendBrick, 0);
        for (int h = hits.length - 1; h >= 0; h--) {
            sb[h] = totalBrick - rank[findParent(p, V)] + 1;
            int r = hits[h][0];
            int c = hits[h][1];
            if (grid[r][c] == 1 && ng[r][c] != 1) {
                ng[r][c] = 1;
                totalBrick++;
                mergeAdjacentBrick(ng, m, n, r, c, p, rank,V );
                int flippedBrickRoot = findParent(p, r * n + c);
                int topRoot = findParent(p, V);
                flippedBrickAmongFallendBrick[h] = flippedBrickRoot != topRoot ? 1 : 0;
            }
        }
        int previouslyFallenBrick = totalBrick - rank[findParent(p, V)] + 1;
      /*  System.out.println("*" + previouslyFallenBrick);
        System.out.println(Arrays.toString(sb));
        System.out.println( Arrays.toString(flippedBrickAmongFallendBrick));*/
        for (int i = 0; i < hits.length;i++){
            int hold = sb[i];
            sb[i] = sb[i] + flippedBrickAmongFallendBrick[i] - previouslyFallenBrick ;
            previouslyFallenBrick = hold;
        }

        return sb;

    }

    private void mergeAdjacentBrick(int[][] g, int m, int n, int r, int c, int[] p, int[] rank, int V) {
        if (r == 0){
            union(p, rank, r *n + c, V);
        }
        for (int i = 0; i < dx.length; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && g[nr][nc] == 1) {
                union(p, rank, r * n + c, nr * n + nc);
            }
        }
    }

    private int findParent(int[] p, int v) {
        if (v == p[v]) {
            return v;
        } else {
            return p[v] = findParent(p, p[v]);
        }
    }

    private void union(int[] p, int[] rank, int a, int b) {
        a = findParent(p, a);
        b = findParent(p, b);
        if (a != b) {
            if (rank[a] < rank[b]) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            p[b] = a;
            /*if (rank[a] != rank[b]){
                rank[b]++;
            }*/
            rank[a] += rank[b];
        }
    }

}
