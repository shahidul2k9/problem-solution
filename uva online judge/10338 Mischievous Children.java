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
      BigInteger fact[] = new BigInteger[21];
      boolean ak[] = new boolean[21];
        fact[0] = fact[1] = BigInteger.ONE;
        for(int i = 2; i <= 20; i++)
                fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
        Scanner scanner = new Scanner(System.in);
        String name;
        BigInteger ans;
        int test;
        int cs = 0;
        test = scanner.nextInt();
        scanner.nextLine();
        while (test-- >0) {
            name = scanner.nextLine();

            ans = fact[name.length()];
            for(int i = 0; i < name.length(); i++)
                    ak[i] = false;
            for(int i = 0; i < name.length();i++){
                             if(ak[i] == false){
                                 ak[i] = true;
                                 int k = 1;
                                 for(int j = i + 1; j < name.length(); j++)
                                     if(name.charAt(i) == name.charAt(j))
                                                    k++;
                                 ans = ans.divide(BigInteger.valueOf(k));
                             }
            }
            cs += 1;
            System.out.println("Data set " + cs + ": " + ans);


        }


    }
}
