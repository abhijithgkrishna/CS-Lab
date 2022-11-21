/** Java program to check the frequency of a given character in a string which is entered by the user */

import java.util.Scanner;

public class FreqStr{
	public static void main(String[] args){
		String str;
		char key;
		int count = 0, i,len;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter string ");
		str  = sc.nextLine();
		System.out.println("Enter key to search ");
		key = sc.next().charAt(0);
		len = str.length();
		for (i = 0;i<len;i++) {
			if (key == str.charAt(i)) {
				count ++;
			}
		}
		System.out.println("count is "+count);
	}
}