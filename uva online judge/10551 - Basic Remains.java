import java.math.BigInteger;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		int b;
		BigInteger p,m;
		Scanner sc = new Scanner(System.in);
		while(true){
			b = sc.nextInt();
			if(b==0)break;
			p = sc.nextBigInteger(b);
			m = sc.nextBigInteger(b);
			System.out.println(p.mod(m).toString(b));
			
		}
		

	}
}
