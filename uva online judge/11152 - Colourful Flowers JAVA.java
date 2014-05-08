import static java.lang.Math.*;
import java.util.Scanner;
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		double a,b,c,s,triangleArea,radiousOfIncircle,radiousOfCircumcircle,areaOfInnercircle;
		while(sc.hasNextDouble()){
			a = sc.nextDouble();
			b = sc.nextDouble();
			c = sc.nextDouble();
			s = (a+b+c)/2;
			triangleArea = sqrt(s*(s-a)*(s-b)*(s-c));
			radiousOfIncircle = triangleArea/s;
			radiousOfCircumcircle = a*b*c/sqrt(2*s*(b+c-a)*(c+a-b)*(a+b-c));
			areaOfInnercircle = PI*radiousOfIncircle*radiousOfIncircle;
			System.out.printf("%.4f %.4f %.4f\n",((PI*radiousOfCircumcircle*radiousOfCircumcircle)-triangleArea),(triangleArea-areaOfInnercircle),areaOfInnercircle);
		}
	}

}
