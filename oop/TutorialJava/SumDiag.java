/** Java program to find the sum of diagonal elements of a matrix */

import java.util.Scanner;

public class SumDiag{
	public static void main(String[] args){
		Scanner sc  = new Scanner(System.in);
		int m,i,j,sumD = 0;
		System.out.println("Enter the order of square matrix : ");
		m = sc.nextInt();
		int a[][] = new int[m][m];
		System.out.println("Enter array elements : ");
		for (i = 0;i<m;i++) {
			for (j = 0;j<m;j++) {
				a[i][j] = sc.nextInt();
			}
		}
		for (i = 0;i<m;i++) {
			sumD += a[i][i];
		}
		System.out.println("Sum of diagonal elements  = " + sumD);

	}
}