/** Java program to find the difference b/w largest and smallest elements in an array */

import java.util.Scanner;

public class Diff{
	public static void main(String[] args ){
		Scanner sc = new Scanner(System.in);
		int a[] = new int[10];
		int lar,sm,i,n,dif;
		System.out.println("Enter number of elements in the array :");
		n = sc.nextInt();
		System.out.println("Enter array elements one by one");
		for (i = 0;i<n;i++) {
			a[i] = sc.nextInt();
		}
		sm = a[0];
		lar = a[0];
		for (i = 1;i<n;i++) {
			if (a[i]<sm) {
				sm = a[i];
			}
			else if(a[i]>lar) {
				lar = a[i];
			}
		}
		dif = lar - sm;
		System.out.println("difference between largest and smallest elements is "+ dif);
	}
}