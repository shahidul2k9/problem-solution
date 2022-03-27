
/**
 * @author Shahidul Islam
 * @date 2/1/2022
 **/
public class _134_GasStation {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int cd = 0;
        int td = 0;
        int n = gas.length;

        int i, s;
        i = s = 0;
        for (i = 0; i < n; i++) {
            int d = gas[i] - cost[i];
            td += d;
            cd += d;
            if (cd < 0) {
                cd = 0;
                s = i + 1;
            }
        }
        if (td >= 0 && i == n) {
            return s;
        } else {
            return -1;
        }
    }
}
