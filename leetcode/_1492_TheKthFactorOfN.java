
/**
 * @author Shahidul Islam
 * @date 2/26/2022
 **/
public class _1492_TheKthFactorOfN {
    private static boolean[] prime = new boolean[1000 + 1];

    int kthFactor(int n, int k) {

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                k--;
                if (k == 0) {
                    return i;
                }
            }
        }
        return -1;
    }
}
