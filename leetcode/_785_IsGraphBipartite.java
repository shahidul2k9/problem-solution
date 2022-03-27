
/**
 * @author Shahidul Islam
 * @date 2/3/2022
 **/
public class _785_IsGraphBipartite {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] p = new int[n];
        int[] rank = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
            rank[i] = 0;
        }

        for (int u = 0; u < n; u++) {
            int pu = findParent(p, u);
            for (int j = 0; j < graph[u].length; j++) {
                int v = graph[u][j];
                int pv = findParent(p, v);
                if (pu == pv){
                    return false;
                }
            }

            for (int j = 1; j < graph[u].length; j++) {
                int v1 = graph[u][j];
                int v2 = graph[u][j-1];
                union(p, rank, v1, v2);
            }
        }
        return true;
    }

    private int findParent(int[] p, int u) {
        int v = p[u];
        if (u == v) {
            return u;
        } else {
            return p[u] = findParent(p, v);
        }
    }

    private void union(int[] p,int[] rank, int u, int v) {
        int pu = findParent(p, u);
        int pv = findParent(p, v);
        if (pu != pv){
            if (rank[pu] < rank[pv]){
                int tmp = pu;
                pu = pv;
                pv = tmp;
            }
            p[pv] = pu;
            if (rank[pu] == rank[pv]) rank[pv]++;
        }
    }
}
