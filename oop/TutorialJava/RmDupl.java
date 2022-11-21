/** Java program to remove the duplicate elements of array and return the new length */

import java.util.Scanner;
import java.util.Arrays;

public class RmDupl{
	public static void main(String[] args) {
		int n,i,j,len;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Number of elements in array :");
		n = sc.nextInt();
		int a[] = new int[n];
		System.out.println("Enter array elements : ");
		for (i=0;i<n;i++) {
			a[i] = sc.nextInt();
		}
		Arrays.sort(a);
		j = 0;
		for (i=1;i<n;i++) {
			if (a[i-1] != a[i]) {
				a[j++] = a[i-1];
			}
		}
		a[j] = a[n-1];
		System.out.println("Length after removing is "+(j+1));

	}
}