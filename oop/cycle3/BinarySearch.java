import java.util.Scanner;

public class BinarySearch{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n,i,low,mid,high,key;
		System.out.println("Enter number of elements : ");
		n = sc.nextInt();
		int[] a = new int[n];
		System.out.println("Enter the asc sorted array : ");
		for (i = 0;i<n;i++) {
			a[i] = sc.nextInt();
		}
		System.out.println("Enter key to search :");
		key = sc.nextInt();
		low = 0;
		high = n-1;
		while (low <= high){
			mid  = (low+high)/2;
			if(key==a[mid]){
				System.out.println("Element found at position " +(mid+1));
				break;
			}
			else if(key < a[mid])
				high = mid-1;
			else
				low = mid+1;
		}
		if (low>high)
			System.out.println("Element not found");
	}
}