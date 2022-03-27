
/**
 * @author Shahidul Islam
 * @date 1/23/2022
 **/
public class _66_PlusOne {

    public int[] plusOne(int[] digits) {
        int[] sum = new int[digits.length];
        int c = 1;
        for (int i = digits.length - 1; i >= 0; i--){
            c = c + digits[i];
            sum[i] = c %10;
            c = c /10;
        }
        if (c > 0){
            int[] extendedSum = new int[sum.length + 1];
            extendedSum[0] = c;
            System.arraycopy(sum, 0, extendedSum, 1, sum.length);
            return extendedSum;
        }else {
            return sum;
        }

    }
}
