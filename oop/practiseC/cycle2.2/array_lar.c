#include<stdio.h>

void main()
{
	int A[20],B[20],m,n,i,j,temp,lar,flag = 0;
	printf("Enter the number of elements of A: \n");
	scanf("%d",&m);
	printf("Enter elements :\n");
	for ( i = 0; i < m; ++i)
	{
		scanf("%d",&A[i]);
	}
	printf("Enter the number of elements of B : \n");
	scanf("%d",&n);
	printf("Enter elements :\n");
	for ( i = 0; i < n; ++i)
	{
		scanf("%d",&B[i]);
	}
	for ( i = 0; i < m-1; ++i)
	{
		for ( j = 0; j < m-1-i; ++j)
		{
			if (A[j]<A[j+1])
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}

	for ( i = 0; i < m; ++i)
	{
		flag = 0;
		for ( j = 0; j < n; ++j)
		{
			if (A[i] == B[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			lar = A[i];
			break;
		}
	}
	printf("Largest is %d \n",lar);

}