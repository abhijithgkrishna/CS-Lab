/** Java program to check if a number is prime or not */

import java.util.Scanner ;

public class Primeornot{
	public static void main(String[] args){
		int num,i,flag = 0;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number : ");
		num = sc.nextInt();
		while(num != 0 && num != 1){
			for(i = 2;i<=num/2;i++){
				if(num%i == 0)
				{
					flag++;
					break;
				}
			}
			if (0 == flag) {
				System.out.println(num + " is prime ");
			}
			else{
				System.out.println(num+" is not prime ");
			}
			break;
		}
		if (num == 0 || num == 1) {
			System.out.println(num+" is not prime ");
		}
	}
} 