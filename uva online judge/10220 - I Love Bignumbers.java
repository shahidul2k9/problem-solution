
import java.util.Scanner;
import java.math.BigInteger;
public class Main{
 public static void main(String[] args) {
     Scanner sc = new Scanner(System.in);
     int n,len,digitSum;
     String str ;
	 while(sc.hasNextInt()){
		 n = sc.nextInt();
		 
     BigInteger factorial = BigInteger.ONE;
     
     for (int i=1; i<=n; i++) {
         factorial = factorial.multiply(BigInteger.valueOf(i));
     }
     str = factorial.toString();
     len = str.length();
     digitSum = 0;
     for(int i =0;i<len;i++)
    	 digitSum = digitSum + str.charAt(i)-48;
     //System.out.println(n+"!");
     //System.out.println(factorial);
     System.out.println(digitSum);
	 }
     
 }
}