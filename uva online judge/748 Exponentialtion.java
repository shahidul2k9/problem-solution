import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Properties;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: shahidul
 * Date: 6/21/13
 * Time: 9:19 AM
 * To change this template use File | Settings | File Templates.
 */
public class Main {

    public static void main(String args[]) {


        BigDecimal R;
        int N;
        String ans ;
        int lo, hi;
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
               R = scanner.nextBigDecimal();
               N = scanner.nextInt();
            ans = R.pow(N).toPlainString();
            lo = 0;
            while(ans.charAt(lo) == '0') lo++;
            hi = ans.length()-1;
            while (ans.charAt(hi) == '0')
                hi--;
            for(int i = lo; i <= hi; i++)
                   System.out.print(ans.charAt(i));
            System.out.println();
        }


    }
}
