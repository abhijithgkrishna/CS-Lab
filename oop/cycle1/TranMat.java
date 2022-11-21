/** Java program to find the transpose of a matrix*/

import java.util.Scanner;

public class TranMat{
	public static void main(String[] args){
		int mat[][] = new int [10][10];
		int tra[][] = new int [10][10];
		int i,j,m,n;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter order of matrix ");
		m = sc.nextInt();
		n = sc.nextInt();
		System.out.println("Enter elements : ");
		for (i = 0;i<m;i++) {
			for (j = 0;j<n;++j) {
				mat[i][j] = sc.nextInt();
			}
		}
		System.out.println("The matrix is : ");
		for (i = 0;i<m;++i) {
			for (j = 0;j<n;++j) {
				System.out.print(mat[i][j]+"	");
			}
			System.out.println();
		}
		for (i = 0;i<n;i++) {
			for (j = 0;j<m;++j) {
				tra[i][j]=mat[j][i];
			}
		}
		System.out.println("The transpose is : ");
		for (i=0;i<n;++i) {
			for (j = 0;j<m;j++) {
				System.out.print(tra[i][j] +"	");
			}
			System.out.println();
		}

	}
}	