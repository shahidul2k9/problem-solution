
/**
 * @author Shahidul Islam
 * @date 2/18/2022
 **/
public class _2149_RearrangeArrayElementsBySign {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        int[] ws = new int[n];
        int po = 0;
        int ne = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                while (nums[po] < 0)
                    po++;
                ws[i] = nums[po++];
            } else {
                while (nums[ne] > 0)
                    ne++;
                ws[i] = nums[ne++];
            }
        }
        return ws;

    }
}
