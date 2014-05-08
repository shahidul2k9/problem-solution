import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<BigInteger> list = new ArrayList<BigInteger>();
		BigInteger el, end, pro, maxPro;
		end = new BigInteger("-999999");
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			el = sc.nextBigInteger();
			if(el.compareTo(end)!=0)list.add(el);
			else{
				maxPro = list.get(0);
				for(int i = 0; i < list.size(); i++){
					pro = BigInteger.ONE;
					for(int j = i; j < list.size(); j++){
						pro = pro.multiply(list.get(j));
						maxPro = maxPro.max(pro);
					}
				}
			System.out.println(maxPro);
			list.clear();
			}
		}
	}

}
