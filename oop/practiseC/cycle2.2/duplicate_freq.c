#include<stdio.h>

void main()
{
	int A[30],n,i,j,count =0;
	printf("Enter the number of elements : \n");
	scanf("%d",&n);
	printf("Enter elements (positive numbers ): \n");
	for ( i = 0; i < n; ++i)
		scanf("%d",&A[i]);
	for ( i = 0; i < n; ++i)
	{
		for ( j = i+1; j < n; ++j)
		{
			if(A[i] == -1)
				continue;
			if (A[i] == A[j])
			{
				count ++;
				A[j] = -1;
			}
		}
	}
	printf("The number of duplicates = %d \n",count);
}