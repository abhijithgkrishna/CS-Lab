
/** Java program to find continuous sub array whose sum is equal to given number */

import java.util.Scanner;

public class SubArray {
	public static void main(String[] args) {
		int n, i, j, num, sum, k;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of elements in array : ");
		n = sc.nextInt();
		int a[] = new int[n];
		System.out.println("Enter array elements one by one : ");
		for (i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		System.out.println("Enter the number : ");
		num = sc.nextInt();
		for (i = 0; i < n; i++) {
			sum = 0;
			for (j = i; j < n; j++) {
				if (sum == num) {
					System.out.println("continuous sub array is :");
					for (k = i; k < j; k++) {
						System.out.print(a[k] + ",");
					}
					System.out.println();
					break;
				}
				if (sum < num) {
					sum += a[j];
				}
				if (sum > num) {
					break;
				}

			}
		}
	}
}
