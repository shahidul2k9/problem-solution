
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 1/23/2022
 **/
public class _219_ContainsDuplicateII {
    static class Np {
        Np(int val, int pos) {
            this.val = val;
            this.pos = pos;
        }

        public int val;
        public int pos;
    }

    public boolean containsNearbyDuplicate(int[] nums, int k) {
        List<Np> numberList = new ArrayList<>(nums.length);
        for (int i = 0; i < nums.length; i++) {
            numberList.add(new Np(nums[i], i));
        }
        numberList.sort((o1, o2) -> {
            if (o1.val  != o2.val) {
                return o1.val - o2.val;
            } else {
                return o1.pos - o2.pos;
            }
        });
        for (int i = 0; i < numberList.size() - 1; i++) {
            if (numberList.get(i).val == numberList.get(i + 1).val
                    && Math.abs(numberList.get(i).pos - numberList.get(i + 1).pos) <= k) {
                return true;
            }
        }
        return false;
    }
}
