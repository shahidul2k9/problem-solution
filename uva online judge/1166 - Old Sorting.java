import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int test,n,swaps,cs = 0;
		int[] in,pos;
		Scanner sc = new Scanner(System.in);
		test = sc.nextInt();
		while((test--)>0){
			n = sc.nextInt();
			in =  new int[n+1];
			pos =  new int[n+1];
			
			for(int i = 1; i<=n; i++){
				in[i] = sc.nextInt();
				pos[in[i]] = i;
			}
			swaps = 0;
			for(int i = 1; i<=n; i++){
				if(in[i] != i){
					in[pos[i]] = in[i];
					pos[in[i]] = pos[i];
					in[i] = i;
					swaps++;
				}
			}
		System.out.printf("Case %d: %d\n", ++cs, swaps);
		}
	}

}
