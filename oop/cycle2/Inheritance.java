import java.util.Scanner;

class Employee{
	String name;
	int age;
	int phone;
	String address;
	int salary;
	void printsal(){
		System.out.println("Salary is "+ salary);
	}
}
class Officer extends Employee{
	String specialisation;
}
class Manager extends Employee{
	String dept;
}

public class Inheritance{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Officer o = new Officer();
		Manager m = new Manager();
		System.out.println("Officer Details : ");
		System.out.print("Enter details in the following order :\nName \nAge \nPhone \nAddress \nSalary \nSpecialisation\n");
		o.name = sc.next();
		o.age = sc.nextInt();
		o.phone = sc.nextInt();
		o.address = sc.next();
		o.salary = sc.nextInt();
		o.specialisation = sc.next();
		System.out.println("Manager Details : ");
		System.out.print("Enter details in the following order :\nName \nAge \nPhone \nAddress \nSalary \nDept\n");
		m.name = sc.next();
		m.age = sc.nextInt();
		m.phone = sc.nextInt();
		m.address = sc.next();
		m.salary = sc.nextInt();
		m.dept = sc.next();
		System.out.println("Officer details :");
		System.out.print(o.name+","+o.age+","+o.phone+","+o.address+","+o.specialisation+"\n");
		o.printsal();
		System.out.println("Manager details :");
		System.out.print(m.name+","+m.age+","+m.phone+","+m.address+","+m.dept+"\n");
		m.printsal();	
	}
}