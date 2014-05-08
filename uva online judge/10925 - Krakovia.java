import java.math.BigInteger;
import java.util.Scanner;
import java.util.Vector;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n,f,testCase=1;
		BigInteger sum = BigInteger.ZERO; 
		BigInteger average;
		Vector<BigInteger> v = new Vector<BigInteger>();
		while(true){
			n = sc.nextInt();
			f = sc.nextInt();
			if(n==0&&f==0)break;
			for(int i=0;i<n;i++){
				v.add(sc.nextBigInteger());
			}
			for(BigInteger big : v)
			sum = sum.add(big);
			average = sum.divide(BigInteger.valueOf(f));
			System.out.println("Bill #"+testCase+" costs "+sum+": each friend should pay "+average);
			System.out.println();
			testCase=testCase+1;
			sum = BigInteger.ZERO;
			v.clear();
		}
		
	}

}
