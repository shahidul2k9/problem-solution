
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 1/23/2022
 **/
public class _207_CourseSchedule {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < prerequisites.length; i++) {
            graph.get(prerequisites[i][1]).add(prerequisites[i][0]);
        }

        int[] color = new int[numCourses];
        Arrays.fill(color, 0);
        for (int i = 0; i < numCourses; i++) {
            if (color[i] == 0) {
               if(!dfs(i, graph, color)){
                   return false;
               }
            }
        }
        return true;

    }

    private boolean dfs(int u, List<List<Integer>> graph, int[] color) {
        color[u] = 1;
        for (int k = 0; k < graph.get(u).size(); k++) {
            int v = graph.get(u).get(k);
            if (color[v] == 1) {
                return false;
            } else if (color[v] == 0) {
                if (!dfs(v, graph, color)){
                    return false;
                };
            }
        }
        color[u] = 2;
        return true;

    }
}
