
/**
 * @author Shahidul Islam
 * @date 2/5/2022
 **/
public class _287_FindTheDuplicateNumber {

    public int findDuplicate(int[] nums) {
       int t, h;
       t = h = nums[0];
       while (true){
           t = nums[nums[t]];
           h = nums[h];
           if (t == h)break;
       }

       t = nums[0];
       while (t != h){
           t = nums[t];
           h = nums[h];
       }
       return h;
    }
}
