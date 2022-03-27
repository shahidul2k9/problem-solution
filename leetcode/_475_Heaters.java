
import java.util.Arrays;

/**
 * @author Shahidul Islam
 * @date 2/17/2022
 **/
public class _475_Heaters {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(houses);
        Arrays.sort(heaters);
        int left = Integer.MIN_VALUE;
        int R = 0;
        int houseIndex = 0;
        int n = houses.length;
        for (int heaterIndex = 0; heaterIndex <= heaters.length; heaterIndex++) {
            int right = (heaterIndex == heaters.length ? Integer.MAX_VALUE : heaters[heaterIndex]);

            while (houseIndex < n && houses[houseIndex] >= left && houses[houseIndex] <= right) {
                int cr = Integer.MAX_VALUE;
                if (left != Integer.MIN_VALUE)
                    cr = houses[houseIndex] - left;
                if (right != Integer.MAX_VALUE)
                    cr = Math.min(cr, right - houses[houseIndex]);
                R = Math.max(R, cr);
                houseIndex++;
            }
            left = right;
        }
        return R;

    }
}
