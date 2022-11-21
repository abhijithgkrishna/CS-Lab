import java.util.Scanner;

interface int1 {
	void fn1();
}

interface int2 {
	void fn2();
}

class Test implements int1, int2 {
	public void fn1(){
		System.out.println("Implemented first interface ");
	}
	public void fn2(){
		System.out.println("Implemented second interface ");
	}
}

public class Interface {
	public static void main(String[] args) {
		Test obj = new Test();
		obj.fn1();
		obj.fn2();
	}
}