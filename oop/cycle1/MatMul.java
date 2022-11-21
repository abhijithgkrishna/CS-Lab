/** Java program to multiply two matrices*/

import java.util.Scanner;

public class MatMul{
	public static void main(String[] args){
		int matA[][] = new int [10][10];
		int matB[][] = new int [10][10];
		int matC[][] = new int [10][10];
		int m,n,p,q,k,i,j;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter order of matrix A ");
		m = sc.nextInt();
		n = sc.nextInt();
		System.out.println("Enter order of matrix B ");
		p = sc.nextInt();
		q = sc.nextInt();
		if (n!=p) {
			System.out.println("Multiplication not possible ");
		}
		else{
			System.out.println("Enter elements of A ");
			for ( i = 0; i < m; ++i)
			{
				for ( j = 0; j < n; ++j)
				{
					matA[i][j] = sc.nextInt();
				}
			}
			System.out.println("Enter elements of B ");
			for ( i = 0; i < p; ++i)
			{
				for ( j = 0; j < q; ++j)
				{
					matB[i][j] = sc.nextInt();
				}
			}
			for ( i = 0; i < m; ++i)
			{
				for ( j = 0; j< q; ++j)
				{
					matC[i][j] = 0;
					for ( k = 0; k < n; ++k)
					{
						matC[i][j] += matA[i][k]*matB[k][j];
					}
				}
			}
			System.out.println("The Product is : ");
			for ( i = 0; i < p; ++i)
			{
				for ( j = 0; j < q; ++j)
				{
					System.out.print(matC[i][j]+"	");
				}
				System.out.println();
			}
		}
	}
}