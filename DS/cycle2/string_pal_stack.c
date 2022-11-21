#include<stdio.h>
#include<string.h>
#define MAX 10

char STACK[MAX];
int TOP;

 
char pop(char a[])
{
	char temp;
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
	int l,i;
	char rev[30];
	printf("Enter string : \n");
	scanf("%s",STACK);
	l = strlen(STACK);
	TOP = l-1;
	for (i = 0; i < l; ++i)
	{
		rev[i] = pop(STACK);
	}
	rev[i] = '\0';
	if (strcmp(STACK,rev) == 0)
	{
		printf("Palindrome \n");
	}
	else
		printf("Not a palindorme \n");
}