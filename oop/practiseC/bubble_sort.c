#include<stdio.h>

void main()
{
	int A[25],i,j,temp,n;
	printf("Enter the number of elements : \n");
	scanf("%d",&n);
	printf("Enter elements :\n");
	for ( i = 0; i < n; ++i)
	{
		scanf("%d",&A[i]);
	}
	for ( i = 0; i < n-1; ++i)
	{
		for ( j = 0; j < n-1-i; ++j)
		{
			if (A[j]>A[j+1])
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
	printf("The sorted array is : \n");
	for ( i = 0; i < n; ++i)
	{
		printf("%d\t",A[i]);
	}
}