import java.util.Scanner;
import static java.lang.Math.*;
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double s,r,angle,R;
		r = 6440;
		String str;
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			s = sc.nextDouble();
			angle = sc.nextDouble();
			str = sc.nextLine();    
			if(str.equals(" min"))
				angle = angle/60;
			if(angle>180)
				angle = 360-angle;
			R = r+s;
			angle = PI/180*angle;
			System.out.printf("%.6f %.6f\n",(R*angle),sqrt(2*R*R*(1-cos(angle))));
		}
	}

}
