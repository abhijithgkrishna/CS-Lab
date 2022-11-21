#include<stdio.h>

void main()
{
	int a[20],i,small,secsmall,sum,n;
	printf("enter number of elements : \n");
	scanf("%d",&n);
	printf("Enter number of elements one by one : \n");
	for ( i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	for ( i = 0; i < n; ++i)
	{
		sum += a[i];
	}
	small = sum	;
	secsmall = sum	;
	for (i = 0; i < n; ++i)
	{
		if (a[i] < secsmall)
		{
			if (a[i] <= small)
			{
				secsmall = small;
				small = a[i];
			}
			else
				
				secsmall = a[i];
		}
	}
	printf("%d is the second smallest element \n", secsmall);
}