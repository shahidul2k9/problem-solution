import java.math.BigInteger;
import java.util.Scanner;
public class Main {
	public static void main(String args[]){
	Scanner sc = new Scanner(System.in);
	int i,index;
	BigInteger ob[] = new BigInteger[1001];
	ob[0] = BigInteger.ONE;
	ob[1] = BigInteger.ONE.add(BigInteger.ONE);
	for(i=2;i<1001;i++)ob[i] = ob[i-1].add(ob[i-2]);
	while(sc.hasNextInt()){
		index = sc.nextInt();
		System.out.println(ob[index]);
	}
	}
}
