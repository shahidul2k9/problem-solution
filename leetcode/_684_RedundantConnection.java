
/**
 * @author Shahidul Islam
 * @date 1/28/2022
 **/
public class _684_RedundantConnection {
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        int[] parent = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for (int[] edge : edges) {
            int u = findParent(edge[0], parent);
            int v = findParent(edge[1], parent);
            if (u == v) {
                return edge;
            } else {
                parent[u] = v;
            }
        }
        return new int[]{0, 0};
    }

    private int findParent(int u, int[] parent) {
        if (parent[u] == u) {
            return u;
        } else {
            return parent[u] = findParent(parent[u], parent);
        }
    }
}
