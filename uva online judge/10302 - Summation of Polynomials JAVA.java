import java.util.Scanner;
import java.math.BigInteger;;
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		BigInteger n;
		while(sc.hasNextBigInteger()){
			n = sc.nextBigInteger();
			n = n.multiply(n.add(BigInteger.ONE)).divide(BigInteger.valueOf(2));
			System.out.println(n.multiply(n));
		}

	}

}
