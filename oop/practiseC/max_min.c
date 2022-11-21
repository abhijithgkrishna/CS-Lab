#include<stdio.h>

void fn(int a, int b)
{
	printf("Upper bound : %d \n",b-1);
	printf("Lower bound : %d \n",a+1);
}

void main()
{
	int m,n;
	printf("Enter the range : \n");
	scanf("%d%d",&m,&n);
	fn(m,n);
}