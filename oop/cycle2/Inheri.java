import java.util.Scanner;

class Employe{
	void display(){
		System.out.println("Name of class is Employe");
	}
	void calcSal(){
		System.out.println("Salary is 10000");
	}
}

class Engineer extends Employe{
	void calcSal(){
		System.out.println("salary is 20000");
		super.calcSal();
	}
}

public class Inheri{
	public static void main(String[] args) {
		Engineer e = new Engineer();
		e.display();
		e.calcSal();

	}
}