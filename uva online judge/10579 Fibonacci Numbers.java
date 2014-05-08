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
    public  static  final int LIMIT = 5000;
    public static void main(String args[]){
        BigInteger fib[] = new BigInteger[LIMIT+1];
        fib[0] = BigInteger.ZERO;
        fib[1] = fib[2] = BigInteger.ONE;
        for(int i = 3; i <= LIMIT; i++)
            fib[i] = fib[i-1].add(fib[i-2]);
        Scanner is = new Scanner(System.in);
        int n;
        while(is.hasNextInt()){
            n = is.nextInt();
            System.out.println(fib[n]);
        }

    }
}
