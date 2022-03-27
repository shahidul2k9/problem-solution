
/**
 * @author Shahidul Islam
 * @date 2/19/2022
 **/
public class _397_IntegerReplacement {
    public int integerReplacement(int n) {
        return (int) findMinOperation(n);
    }

    private long findMinOperation(long n) {
        if (n == 1)
            return 0;
        else if ((n & 1) == 0) {
            return 1 + findMinOperation(n >> 1);
        } else return 1 + Math.min(findMinOperation(n + 1), findMinOperation(n - 1));
    }
}
