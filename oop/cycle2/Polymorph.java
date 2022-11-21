abstract class Shape{
	abstract void noOfSides();
}

class Rectangle extends Shape{
	void noOfSides(){
		System.out.println("Number of sides is 4");
	}
}
class Triangle extends Shape{
	void noOfSides(){
		System.out.println("Number of sides is 3");
	}
}
class Hexagon extends Shape{
	void noOfSides(){
		System.out.println("Number of sides is 6");
	}
}

public class Polymorph{
	public static void main(String[] args) {
		Hexagon obh = new Hexagon();
		Rectangle obr = new Rectangle();
		Triangle obt = new Triangle();
		obh.noOfSides();
		obr.noOfSides();
		obt.noOfSides();
	}
}