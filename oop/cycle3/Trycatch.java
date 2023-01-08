import java.util.Scanner;

public class Trycatch {
	static void calc(int a, int b) throws ArithmeticException {
		int c = a / b;
		System.out.println("Statement before exception");
		System.out.println("The value of a/b is " + c);
		System.out.println("Statement after exception ");
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a, b;
		System.out.println("Enter Values to divide");
		a = sc.nextInt();
		b = sc.nextInt();
		try {
			calc(a, b);
		} catch (ArithmeticException e) {

			System.out.println("Exception catched");
		} finally {
			System.out.println("normal");
		}

	}
}