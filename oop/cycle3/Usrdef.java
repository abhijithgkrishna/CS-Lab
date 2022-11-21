import java.util.*;

class Myexception extends Exception{
	public String toString(){
		return "Myexception";
	}
}
public class Usrdef{
	static void errorer() throws Myexception{
		throw new Myexception();
	}
	public static void main(String[] args) {
		try{
			errorer();
		}
		catch(Exception k){
			System.out.println(k);
			System.out.println("in catch");
		}
		finally{
			System.out.println("normal flow");
		}
	}
}