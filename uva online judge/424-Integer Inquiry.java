import java.util.Scanner;
import java.math.BigInteger;

public class BigSum {
public static void main(String args[]){	
	BigInteger temp;
	BigInteger sum = new BigInteger("0");
	Scanner sc = new Scanner(System.in);

while(true){
	temp = sc.nextBigInteger();
	if(temp.compareTo(BigInteger.valueOf(0))==0)break;
	sum = sum.add(temp);
	}
System.out.println(sum);
}

}
