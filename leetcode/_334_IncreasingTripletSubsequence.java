
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/12/2022
 **/
public class _334_IncreasingTripletSubsequence {
    private static final long inf = Long.MAX_VALUE;

    public boolean increasingTriplet(int[] nums) {
        int n = nums.length;
        long[] lis = new long[n + 1];
        Arrays.fill(lis, inf);
        lis[0] = -inf;

        for (int i = 0; i < n; i++) {
            int len = findLowerBound(0, n, nums[i], lis);
            lis[len] = nums[i];
        }

        return n >= 3 && lis[3] != inf;
    }

    private int findLowerBound(int low, int high, int val, long[] l) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (l[mid] < val) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

}
