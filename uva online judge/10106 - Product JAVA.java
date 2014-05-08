import java.math.BigInteger;
import java.util.Scanner;
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger x,y;
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			x = sc.nextBigInteger();
			y = sc.nextBigInteger();
			System.out.println(x.multiply(y));
		}

	}

}
