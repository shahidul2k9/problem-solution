
/**
 * @author Shahidul Islam
 * @date 1/28/2022
 **/
public class _547_NumberOfProvinces {
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        int pre[] = new int[n];
        for (int i = 0; i < n; i++) {
            pre[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    int u = findParent(i, pre);
                    int v = findParent(j, pre);
                    if (u != v) {
                        pre[u] = v;
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (pre[i] == i) {
                cnt++;
            }
        }

        return cnt;
    }

    private int findParent(int u, int[] pre) {
        if (pre[u] == u) {
            return u;
        } else {
            return pre[u] = findParent(pre[u], pre);
        }
    }
}
