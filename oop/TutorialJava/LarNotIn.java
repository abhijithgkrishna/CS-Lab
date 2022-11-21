/** Java program to find the largest element in first array which is not present in second array
	Both arrays are inputed by the user */

import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;
public class LarNotIn{
	public static void main(String[] args){
		int  m,n,i,j,flag;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of elements in first array : ");
		m = sc.nextInt();
		int a[] = new int[m];
		System.out.println("Enter array elements one by one");
		for (i = 0;i<m;i++) {
			a[i] = sc.nextInt();
		}
		System.out.println("Enter number of elements in the second array : ");
		n = sc.nextInt();
		int b[] = new int[n];
		System.out.println("Enter array elements one by one ");
		for (i = 0;i<n;i++) {
			b[i] = sc.nextInt();
		}
		Arrays.sort(a);
		for (i=m-1;i>=0;i--) {
			flag = 0;
			for (j = 0;j<n;j++) {
				if(a[i] == b[j])
					flag ++;
			}
			if(flag == 0){
				System.out.println("Element is "+a[i]);
				break;
			}
		}
	}
} 