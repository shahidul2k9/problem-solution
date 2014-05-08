import java.math.BigInteger;
import static java.math.BigInteger.*;
import java.util.Scanner;
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		BigInteger n ,d17;
		d17 = TEN.add(valueOf(7));
		while(true){
			n = sc.nextBigInteger();
			if(n.equals(ZERO))break;
			if(n.mod(d17)==ZERO)System.out.println(1);
			else System.out.println(0);
		}
	}

}
