#include<stdio.h>
#include<stdlib.h>

void main()
{
	int *p, n, i=0, j=0,t;
	printf("Enter the number of elements : \n");
	scanf("%d",&n);
	p = (int*)malloc(n * sizeof(int));
	for ( i = 0; i < n; ++i)
	{
		printf("Enter the %dst element : ",i+1);
		scanf("%d",(p+i));
	}
	for (i =0; i < n-1; ++i)
	{
		for (j =0 ; j < n-1-i; ++j)
		{
			if(*(p+j) > *(p+j+1))
			{
				t = *(p+j);
				*(p+j) = *(p+j+1);
				*(p+j+1) = t;
			}
		}
	}
	printf("The sorted array is \n");
	for ( i = 0; i < n; ++i)
	{
		printf("%d \t", *(p+i));
	}
	free(p);
}