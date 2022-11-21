#include<stdio.h>
#include<stdlib.h>

void main()
{
	int temp,i,n,*p;
	printf("Enter the number of elements : \n");
	scanf("%d",&n);
	p = (int*)malloc(n*sizeof(int));
	printf("Enter Elements : \n");
	for ( i = 0; i < n; ++i)
		scanf("%d",(p+i));
	for ( i = 0; i < n/2; ++i)
	{
		temp = *(p+i);
		*(p+i) = *(p+n-1-i);
		*(p+n-1-i) = temp;
	} 
	printf("The reversed is : \n");
	for ( i = 0; i < n; ++i)
	{
		printf("%d\n",*(p+i));
	}
}