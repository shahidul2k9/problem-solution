import java.util.Scanner;
import static java.lang.Integer.*;
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int tc,ct,n,bone,hone,len;
		String bstr,hstr,str;
		tc = sc.nextInt();
		ct =0;
		while(ct<tc){
			n =sc.nextInt();
			hone =0;
			bone =0;
			
			bstr = toBinaryString(n);
			len =bstr.length();
			for(int i=0;i<len;i++){
				bone = bone +bstr.charAt(i)-48;
			}
			str = Integer.toString(n);
			n = parseInt(str, 16);
			hstr = toBinaryString(n);
			len =hstr.length();
			for(int i=0;i<len;i++){
				hone = hone +hstr.charAt(i)-48;
			}
			System.out.println(bone+" "+hone);
			ct++;
		}

	}

}
