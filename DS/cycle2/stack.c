#include<stdio.h>
#define MAX 5

int TOP = -1;
int STACK[MAX];

void push(int x, int a[])
{
	if (TOP == MAX - 1)
	{
		printf("Stack overflow \n");
		return ;
	}
	TOP++;
	a[TOP] = x;
}
int pop(int a[])
{
	int temp;
	if (TOP == -1)
	{
		printf("Stack underflow\n");
		return -1;
	}
	temp = a[TOP];
	TOP--;
	return temp;
}
void main()
{
	int k,n,i;
	printf("Enter number of elements : \n");
	scanf("%d",&n);
	printf("Enter elements one by one\n");
	for ( i = 0; i < n; ++i)
	{
		scanf("%d",&k);
		push(k,STACK);
	}
	for (int i = 0; i < n; ++i)
	{
		int k = pop(STACK);
		if(k == -1)
			break;
		printf("%d \n",k);
	}
}