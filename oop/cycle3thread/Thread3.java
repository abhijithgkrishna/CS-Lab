import java.lang.Thread;
import java.util.*;

class ThreadOdd extends Thread {
	public void run(){
		System.out.println("Odd numbers are : ");
		for (int i = 1;i<100;i += 2) {
			System.out.print(i + " ");
		}
		System.out.println("");
	}
}

class ThreadEven extends Thread {
	public void run(){
		System.out.println("Even numbers are : ");
		for (int i = 0;i<100;i += 2) {
			System.out.print(i + " ");
		}
			
	}
}

public class Thread3{
	public static void main(String[] args) {
		ThreadOdd obodd = new ThreadOdd();
		ThreadEven obeven = new ThreadEven();
		try{
			obodd.start();
			Thread.sleep(1000);
			obeven.start();
		}catch(Exception e){};
	}
}