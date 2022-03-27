
/**
 * @author Shahidul Islam
 * @date 2/17/2022
 **/
public class _52_NQueensII {
    int total = 0;

    public int totalNQueens(int n) {
        total = 0;
        solve(n, new int[n], 0);
        return total;
    }


    private void solve(int n, int[] sc, int cn) {
        if (cn == n) {
            total++;
        } else {
            for (int c = 0; c < n; c++) {
                if (!isAttacking(sc, cn, c)) {
                    sc[cn] = c;
                    solve(n, sc, cn + 1);
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

}
