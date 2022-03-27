
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

/**
 * @author Shahidul Islam
 * @date 2/7/2022
 **/
public class _210_CourseScheduleII {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] color = new int[numCourses];
        List<List<Integer>> adj = new ArrayList<>(Collections.nCopies(numCourses, null))
                .stream()
                .map(nvl -> new ArrayList<Integer>()).collect(Collectors.toList());
        for (int[] prerequisite : prerequisites) {
            adj.get(prerequisite[1]).add(prerequisite[0]);
        }
        Arrays.fill(color, 0);
        List<Integer> orderList = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            if (color[i] == 0) {
                if (hasCycle(i, color, adj, orderList)) {
                    return new int[]{};
                }
            }
        }
        Collections.reverse(orderList);
        return orderList.stream().mapToInt(Integer::intValue).toArray();

    }

    private boolean hasCycle(int u, int[] color, List<List<Integer>> g, List<Integer> orderList) {
        color[u] = 1;
        for (int i = 0; i < g.get(u).size(); i++) {
            int v = g.get(u).get(i);
            if (color[v] == 0) {
                if (hasCycle(v, color, g, orderList))
                    return true;
            } else if (color[v] == 1) {
                return true;
            }
        }
        color[u] = 2;
        orderList.add(u);
        return false;

    }
}
