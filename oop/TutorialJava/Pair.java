/** Java program to find all the pairs of elements in an array whose sum is a given number */

import java.util.Scanner;
import java.util.Arrays;

public class Pair{
	public static void main(String[] args) {
		Scanner sc  = new Scanner(System.in);
		int n,val,l,r,i;
		System.out.println("Enter number of elements in the array :");
		n = sc.nextInt();
		int a[] = new int [n];
		System.out.println("Enter the elements one by one : ");
		for (i=0;i<n;i++) {
			a[i] = sc.nextInt();
		}
		System.out.println("Enter the value : ");
		val = sc.nextInt();
		Arrays.sort(a);
		System.out.println(a[n-1]);
		l = 0;
		r = n-1;
		while(l<r) {
			if (a[l]+a[r] == val) {
				System.out.println("("+a[l]+","+a[r]+")");
				l++;
				r--;
			}
			else if (a[l]+a[r] < val) {
				l++;
			}
			else if (a[l]+a[r] > val) {
				r--;
			} 
		}
	}
}