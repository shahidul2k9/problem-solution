
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/3/2022
 **/
public class _1267_CountServersThatCommunicate {
    public int countServers(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[] rn = new int[m];
        int[] cn = new int[n];
        Arrays.fill(rn, 0);
        Arrays.fill(cn, 0);
        for (int r = 0; r < m;r++){
            for (int c = 0; c < n; c ++){
                rn[r] += grid[r][c];
                cn[c] += grid[r][c];
            }
        }
        int connectedComputer = 0;
        for (int r = 0; r < m;r++){
            for (int c = 0; c < n; c ++){
                if (rn[r] > 1 || cn[c] > 1){
                    connectedComputer += grid[r][c];
                }
            }
        }
        return connectedComputer;
    }
}
