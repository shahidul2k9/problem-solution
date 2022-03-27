
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 1/28/2022
 **/
public class _90_SubsetsII {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> powerSet = new ArrayList<>();
        bk(0, nums, new ArrayList<>(), powerSet);
        return powerSet;
    }
    private void bk(int pos,int []nums, List<Integer> subSet, List<List<Integer>> powerSet){
        if (pos >= nums.length){
            powerSet.add(new ArrayList<>(subSet));
        }else {
            subSet.add(nums[pos]);
            bk(pos+1, nums, subSet, powerSet);
            subSet.remove(subSet.size()-1);
            int skipCount = 1;
            while (pos + skipCount < nums.length && nums[pos + skipCount] == nums[pos]){
                skipCount++;
            }
           // if (pos + skipCount < nums.length){
                bk(pos+skipCount, nums, subSet, powerSet);
            //}
        }
    }
}
