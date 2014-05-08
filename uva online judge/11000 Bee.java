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
    public static void main(String args[]){
        long F[][] = new long[100][2];
        F[0][0] = 1;
        F[0][1] = 0;
        for(int i = 1; i <100; i++){
            F[i][0] = 1 + F[i-1][1];
            F[i][1] = F[i-1][0] + F[i-1][1];
        }

        int n;
        long total;
        Scanner scanner = new Scanner(System.in);
        while(scanner.hasNextInt()){
            n = scanner.nextInt();
            if(n == -1)break;
            total = F[n][1] + F[n][0];
            System.out.println(F[n][1] + " " + total );
        }


    }
}
