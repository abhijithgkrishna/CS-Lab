#include<stdio.h>

void swapval(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swapref(int *a, int *b)
{
	int temp;
	temp = *a;
	*a	  =	*b;
	*b	  =temp;
}

void main()
{
	int n1,n2;
	printf("Enter the numbers : \n");
	scanf("%d%d",&n1,&n2);
	swapval(n1,n2);
	printf("The values after swapping by value are : %d , %d\n",n1,n2);
	swapref(&n1,&n2);
	printf("The values after swapping by reference are : %d , %d\n",n1,n2);
}