import java.lang.Thread;
import java.util.*;

class t1 extends Thread {
	int x;
	int a;
	t1(int a){
		this.a = a;
		this.x = a*a;
	}
	public void run(){
		System.out.println("The number is : "+ a);
		System.out.println("The square is : "+ x);
	}
}

class t2 extends Thread {
	int x;
	int a;
	t2(int a){
		this.x = a*a*a;
		this.a = a;
	}
	public void run(){
		System.out.println("The number is : "+a);
		System.out.println("The cube is : "+ x);
	}
}

class T extends Thread {
	
	public void run(){
		Random r = new Random();
		for (int i = 0 ; i<5 ; i++) {
			int rand = r.nextInt(100);
			if (rand%2 == 0) {

				t1 obj = new t1(rand);
				obj.start();
			}
			else{
				t2 obje = new t2(rand);
				obje.start();
			}
			try{
				Thread.sleep(1000);
			}catch(Exception e)
			{}
		}
	}
}

public class Thread1 {
	public static void main(String[] args) {
		T abc = new T();
		abc.start();
	}
}