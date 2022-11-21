// C program to find smallest element in a list of numbe
#include<stdio.h>

void main()
{
	int n, A[20], *p, small, i;
	p = A; // p points to the first element of the list
	printf("Enter the number of elements : \n");
	scanf("%d",&n);
	for ( i = 0; i < n; ++i)
	{
		printf("Enter the %dst element : ",i+1);
		scanf("%d",p+i);
	}
	small = *p;
	for ( i = 1; i < n; ++i)
	{
		if(small > *(p+i))
			small = *(p+i);
	}
	printf("The smallest element is %d",small);
}