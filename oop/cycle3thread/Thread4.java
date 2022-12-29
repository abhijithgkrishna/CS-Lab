import java.lang.Thread;
import java.io.*;

public class Thread4 extends Thread{
	public static void main(String[] args) {
		Thread4 ob1 = new Thread4();
		Thread4 ob2 = new Thread4();
		Thread4 ob3 = new Thread4();
		ob1.setName("Thread 1");
		ob2.setName("Thread 2");
		ob3.setName("Thread 3");
		System.out.println("Priority of " + ob1.getName() +" is "+ob1.getPriority());
		System.out.println("Priority of " + ob2.getName() +" is "+ob2.getPriority());
		System.out.println("Priority of " + ob3.getName() +" is "+ob3.getPriority());
		System.out.println();
		System.out.println("After changing");
		System.out.println();
		ob1.setPriority(1);
		ob2.setPriority(2);
		ob3.setPriority(3);
		System.out.println("Priority of " + ob1.getName() +" is "+ob1.getPriority());
		System.out.println("Priority of " + ob2.getName() +" is "+ob2.getPriority());
		System.out.println("Priority of " + ob3.getName() +" is "+ob3.getPriority());

	}
}