import java.math.BigInteger;
import java.util.Scanner;
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger p,q,gc;
		String str,pstr,qstr;
		int testCase,currentTestCase,divisonIndex;
		Scanner sc = new Scanner(System.in);
		testCase = sc.nextInt();
		str = sc.nextLine();
		currentTestCase = 0;
		while(currentTestCase<testCase){
			str = sc.nextLine();
			divisonIndex = str.indexOf('/');
			pstr = str.substring(0,divisonIndex-1);
			qstr = str.substring(divisonIndex+2); 
			p = new BigInteger(pstr);
			q = new BigInteger(qstr);
			gc = p.gcd(q);  
			System.out.println(p.divide(gc)+" / "+q.divide(gc));
			currentTestCase++;
		}
	}

}
