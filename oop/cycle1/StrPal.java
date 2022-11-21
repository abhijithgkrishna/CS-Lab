/** Java Program to check if the string entered by user is prime or not */

import java.util.Scanner;

public class StrPal{
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
		if (str.equals(rev) == true) {
			System.out.println("Palindrome");
		}
		else
			System.out.println("Not a Palindrome");
	
	}
}