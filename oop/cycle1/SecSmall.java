/** Java program to find the second smallest number in an array inputted by the user*/
import java.util.Scanner;

public class SecSmall{
	public static void main(String[] args){
		int a[] = new int[10];
		int n,i,sum = 0,small,secsmall;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of elements ");
		n = sc.nextInt();
		System.out.println("Enter array elements : ");
		for (i = 0;i<n;i++) {
			a[i] = sc.nextInt();
		}
		for (i = 0;i<n;i++) {
			sum += i;
		}
		small = sum	;
		secsmall = sum	;
		for (i = 0; i < n; ++i){
			if (a[i] < secsmall){
				if (a[i] <= small){
					secsmall = small;
					small = a[i];
				}
				else
					secsmall = a[i];
			}
		}

		System.out.println("Second smallest element is : "+secsmall);
	}
}