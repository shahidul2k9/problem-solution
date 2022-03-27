
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/7/2022
 **/
public class _204_CountPrimes {
    public int countPrimes(int n) {
        boolean[] s = new boolean[n];
        if (n < 2) {
            return 0;
        } else {
            Arrays.fill(s, true);
            s[0] = s[1] = false;
            for (int i = 2; i <= Math.sqrt(n); i++) {
                if (s[i]) {
                    for (int k = i + i; k < n; k = k + i) {
                        s[k] = false;
                    }
                }
            }
        }

        int p = 0;
        for (int i = 2; i < n; i++) {
            if (s[i]) p++;
        }
        return p;

    }
}
