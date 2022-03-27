
import java.util.ArrayList;
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 2/11/2022
 **/
public class _442_FindAllDuplicatesInAnArray {
    public List<Integer> findDuplicates(int[] nums) {
        int c = 0;
        int n = nums.length;
        while (c < n) {
            int val = nums[c];
            if (val > 0) {
                int existingVal = nums[val - 1];
                if (existingVal > 0) {
                    nums[c] = existingVal;
                    nums[val - 1] = 0;
                } else {
                    nums[val - 1]--;
                    c++;
                }
            } else { //skip
                c++;
            }
        }
        List<Integer> duplicateNumberList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                duplicateNumberList.add(i + 1);
            }
        }
        return duplicateNumberList;

    }
}
