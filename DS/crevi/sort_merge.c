// C program to merge two sorted arrays such that the new array is also sorted

#include<stdio.h>

void main()
{
	int A[20],B[20],C[40],m,n,i,j=0,k=0;
	printf("Enter the size of first sorted array \n");
	scanf("%d",&m);
	for ( i = 0; i < m; ++i)
	{
		printf("Enter the %dst element :",i+1);
		scanf("%d",&A[i]);
	}
	printf("Enter the size of second sorted array \n");
	scanf("%d",&n);
	for ( i = 0; i < n; ++i)
	{
		printf("Enter the %dst element :",i+1);
		scanf("%d",&B[i]);
	}
	i = 0;
	// Comparing elements from both arrays
	// The smaller element is inserted to the new array
	while((i<m)&&(j<n))
	{
		if(A[i]<B[j])
		{
			C[k] = A[i];
			i++;
			k++;
		}
		else if(A[i]>B[j])
		{
			C[k] = B[j];
			j++;
			k++;
		}
		else
		{
			C[k] = A[i];
			i++;
			k++;
			j++;
		}
	}
	if(i == m)
	{
		while(j<n)
		{
			C[k] = B[j];
			k++;
			j++;
		}
	}
	else
	{
		while(i<m)
		{
			C[k] = A[i];
			k++;
			i++;
		}
	}
	printf("The sorted araray is : \n");
	for ( i = 0; i < k; ++i)
	{
		printf("%d \n",C[i]);
	}

}