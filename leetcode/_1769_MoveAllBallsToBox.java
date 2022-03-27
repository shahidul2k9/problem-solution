
/**
 * @author Shahidul Islam
 * @date 1/29/2022
 **/
public class _1769_MoveAllBallsToBox {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int[] lf = new int[n];
        int[] rf = new int[n];
        int[] lc = new int[n];
        int[] rc = new int[n];
        int[] tc = new int[n];


        for (int i = 0; i < n; i++) {
            lf[i] = (i == 0 ? 0 : lf[i - 1]) + boxes.charAt(i) - '0';
        }

        for (int i = n - 1; i >= 0; i--) {
            rf[i] = (i + 1 == n ? 0 : rf[i + 1]) + boxes.charAt(i) - '0';
        }
        lc[0] = rc[n - 1] = 0;
        for (int i = 1; i < n; i++) {
            lc[i] = lc[i - 1] + lf[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            rc[i] = rc[i + 1] + rf[i + 1];
        }
        for (int i = 0; i < n; i++) {
            tc[i] = lc[i] + rc[i];
        }
        return tc;

    }
}
