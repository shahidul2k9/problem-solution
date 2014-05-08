import java.util.Scanner;
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		long a,b,x,it,CT=1;
		while(true){
			a = sc.nextLong();
			b = sc.nextLong();
			if(a<0&&b<0)break;
			it = 1;
			x = a;
			for(;x!=1;){
				if(x%2 == 0)x = x/2;
				else x = 3*x +1;
				if(x >b)break;
				it++;
			}
			System.out.println("Case "+CT+": A = "+a+", limit = "+b+", number of terms = "+it);
			CT++;
		}

	}

}
