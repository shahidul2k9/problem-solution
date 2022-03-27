
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author Shahidul Islam
 * @date 2/3/2022
 **/
public class _399_EvaluateDivision {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        int n = 0;
        Map<String, Integer> nodeMap = new HashMap<>();

        for (List<String> eq : equations) {
            for (String nodeKey : eq) {
                if (!nodeMap.containsKey(nodeKey)) {
                    nodeMap.put(nodeKey, n++);
                }
            }
        }
        double[][] g = new double[n][n];
        int INF = Integer.MAX_VALUE / 4;
        Arrays.stream(g).forEach(row -> {
            Arrays.fill(row, INF);
        });

        System.out.println(nodeMap.toString());
        for (int i = 0; i < equations.size(); i++) {
            List<String> eq = equations.get(i);
            int u = nodeMap.get(eq.get(0));
            int v = nodeMap.get(eq.get(1));
            double w = values[i];
            g[u][v] = w;
            if (w > 0) {
                g[v][u] = 1 / w;
            }
            g[u][u] = 1;
            g[v][v] = 1;
        }

        System.out.println(Arrays.deepToString(g));
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (g[i][k] < INF && g[k][j] < INF) {
                        g[i][j] = g[i][k] * g[k][j];
                    }

                }
            }
        }


        System.out.println(Arrays.deepToString(g));

        double[] solution = new double[queries.size()];
        for (int i = 0; i < queries.size(); i++) {
            List<String> path = queries.get(i);
            String from = path.get(0);
            String to = path.get(1);
            if (nodeMap.containsKey(from) && nodeMap.containsKey(to)) {
                Integer u = nodeMap.get(from);
                Integer v = nodeMap.get(to);
                if (g[u][v] < INF) {

                    solution[i] = g[u][v];
                } else {
                    solution[i] = -1.0;
                }
            } else {
                solution[i] = -1.0;
            }
        }
        return solution;

    }
}
