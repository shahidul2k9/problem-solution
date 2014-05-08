import java.util.Scanner;
import  java.lang.String;
import static java.lang.Integer.*;
public class Main {
	public static void main(String[] args) {
		int intValue;
		Scanner sc = new Scanner(System.in);
		String str;
		while(true){
			str = sc.nextLine();
			if(str.charAt(0)=='-')break;
			if(str.charAt(0)=='0'&&str.charAt(1)=='x'){
				str = str.substring(2);
				System.out.println(parseInt(str,16));
			}
			else{
				intValue = parseInt(str);
				System.out.println("0x"+toHexString(intValue).toUpperCase());
			}
			
		}
	
	}

}
