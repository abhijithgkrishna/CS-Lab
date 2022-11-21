import java.util.Scanner;
import java.lang.Math;

public class Fn_overloading{
	static double area(double r) {
		double area = 3.14*r*r;
		return area;
	}
	static double area(double l, double b){
		return l*b;
	}
	static double area(double a, double b, double c){
		double area, s;
		s = (a+b+c)/2;
		area = Math.sqrt(s*(s-a)*(s-b)*(s-c));
		return area;
	}
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		double a,b,c;
		int choice;
		System.out.println("Enter choice : \n1. Circle\n2. Rectangle\n3. Triangle");
		choice = sc.nextInt();
		switch(choice){
			case 1 :
				System.out.println("Enter radius of circle : ");
				a = sc.nextDouble();
				System.out.println("Area is "+area(a));
				break;
			case 2 :
				System.out.println("Enter length and breadth : ");
				a = sc.nextDouble();
				b = sc.nextDouble();
				System.out.println("Area is "+area(a,b));
				break;
			case 3 :
				System.out.println("Enter length of sides of triangle : ");
				a = sc.nextDouble();
				b = sc.nextDouble();
				c = sc.nextDouble();
				System.out.println("Area is "+area(a,b,c));
				break;
			default :
				System.out.println("Wrong choice");
				break;
		}
	}
}