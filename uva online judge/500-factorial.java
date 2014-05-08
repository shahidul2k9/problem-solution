
import java.util.Scanner;
import java.math.BigInteger;
public class FiveHundredFactorial{
 public static void main(String[] args) {
     Scanner sc = new Scanner(System.in);
     int n;
	 while(sc.hasNextInt()){
		 n = sc.nextInt();
		 
     BigInteger factorial = BigInteger.ONE;
     
     for (int i=1; i<=n; i++) {
         factorial = factorial.multiply(BigInteger.valueOf(i));
     }
     System.out.println(n+"!");
     System.out.println(factorial);
	 }
     
 }
}