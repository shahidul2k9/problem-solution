
import java.util.ArrayList;
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 2/17/2022
 **/
public class _51_NQueens {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> solutionList = new ArrayList<>();
        solve(n, new int[n], 0, solutionList);
        return solutionList;

    }

    private void solve(int n, int[] sc, int cn, List<List<String>> solutionList) {
        if (cn == n) {
            solutionList.add(generateGrid(n, sc));
        } else {
            for (int c = 0; c < n; c++) {
                if (!isAttacking(sc, cn, c)) {
                    sc[cn] = c;
                    solve(n, sc, cn + 1, solutionList);
                }
            }
        }
    }

    private boolean isAttacking(int[] sn, int cn, int c) {
        for (int r = 0; r < cn; r++) {
            if (sn[r] == c || Math.abs(sn[r] - c) == Math.abs(cn - r))
                return true;
        }
        return false;

    }

    private List<String> generateGrid(int n, int[] s) {
        List<String> gridLineList = new ArrayList<>();
        for (int r = 0; r < n; r++) {
            StringBuilder line = new StringBuilder(n);
            for (int c = 0; c < n; c++) {
                line.append(s[r] == c ? 'Q' : '.');
            }
            gridLineList.add(line.toString());

        }
        return gridLineList;
    }
}
