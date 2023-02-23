import java.lang.Thread;
import java.util.*;

class Printer {
	synchronized public static void print(String name) {
		for (int i = 0; i < 5; i++) {
			System.out.println("Now inside " + name);
			try {
				Thread.sleep(500);
			} catch (Exception e) {
				System.out.println(e);
			}
		}
	}
}

class MyThread1 extends Thread {
	public void run() {
		Printer.print(currentThread().getName());
	}
}

class MyThread2 extends Thread {
	public void run() {
		Printer.print(currentThread().getName());
	}
}

public class Thread2 {
	public static void main(String[] args) {
		MyThread1 ob1 = new MyThread1();
		ob1.setName("First Thread");
		MyThread2 ob2 = new MyThread2();
		ob2.setName("Second Thread");
		ob1.start();
		ob2.start();
	}
}