#include<stdio.h>

int fibo(int a)
{
	int fib1,fib2;
	if(a<=1)
		return a;
	fib1 = fibo(a-1);
	fib2 = fibo(a-2);
	return fib1+fib2;
}

void main()
{
	int n,i;
	printf("Enter number : \n");
	scanf("%d",&n);
	for ( i = 0; i < n; ++i)
	{
		printf("%d \t",fibo(i));
	}
}