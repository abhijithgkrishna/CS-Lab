/** Java program to reverse a string which is inputted by the user*/

import java.util.Scanner;

public class RevStr{
	public static void main(String[] args){
		String str,rev ="";
		char a ;
		int len,i;
		Scanner sc  = new Scanner(System.in);
		System.out.println("Enter the string : ");
		str = sc.nextLine();
		len = str.length();
		for (i = 0;i<len;i++ ) {
			rev += str.charAt(len-1-i);
		}
		System.out.println("Reverse is " + rev);
	}
}