import java.util.Scanner;
public class Main {

	/**
	 * @param args
	 */
	public static int sumOfDigit(int x){
		int sum = 0;
		for(int i=x;i!=0;i=i/10){
			sum = sum +i%10;
		}
		if(sum<10)return sum;
		else return sumOfDigit(sum);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc =  new Scanner(System.in);
		int n;
		n = sc.nextInt();
		while(n!=0){
			System.out.println(sumOfDigit(n));
			n = sc.nextInt();
		}
	}

}
