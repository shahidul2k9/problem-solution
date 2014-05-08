import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by shahidul on 12/10/13.
 */
public class Main {
    public static void main(String args[]){

        int test,z;
        Scanner scanner = new Scanner(System.in);
        String X, Z;
        test = scanner.nextInt();
        scanner.nextLine();
        while (test-- > 0){
            X = scanner.nextLine();
            Z = scanner.nextLine();
            BigInteger occ[][] = new BigInteger[Z.length()+1][X.length()+1];



            for (int i = 0; i <= Z.length(); i++)
                occ[i][0] = BigInteger.ZERO;
            for (int c = 0; c <= X.length(); c++)
                occ[0][c] = BigInteger.ONE;

            for (int i = 1; i <=Z.length(); i++)
                for (int k = 1; k <= X.length(); k++){
                    occ[i][k] = occ[i][k-1];
                    if(Z.charAt(i-1) == X.charAt(k-1)) occ[i][k] = occ[i][k].add(occ[i-1][k-1]);
                }
            System.out.println(occ[Z.length()][X.length()]);
        }


    }
}
