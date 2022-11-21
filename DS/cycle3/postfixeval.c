// C program to evaluate a postfix expression

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 20
#define INVAL 999

int S[MAX];
int TOP = -1;

void push(int ch)
{
	if(TOP == MAX-1)
	{
		printf("Stack overflow \n");
	}
	else
	{
		TOP++;
		S[TOP] = ch;
	}
}
int pop()
{
	int temp;
	if (TOP == -1)
	{
		printf("Stack underflow \n");
		return INVAL;
	}
	else
	{
		temp = S[TOP];
		TOP--;
		return temp;
	}
}

int xOPy(int a, int b, char op)
{
	int res;
	switch(op)
	{
		case '+':
			res = a+b;
			break;
		case '-':
			res = a-b;
			break;
		case '*':
			res = a*b;
			break;
		case '/':
			res = a/b;
			break;
		case '^':
			res = pow(a,b);
			break;
	}
	return res;
}

void main()
{
	int i = 0,t,value,x,y;
	char E[20],item,op;
	printf("Enter postfix expression :\n");
	scanf("%s",E);
	strcat(E,"#");
	item = E[i++];
	while(item != '#')
	{
		if (isdigit(item))
		{
			push(item-48);
		}
		else
		{
			op = item;
			y = pop();
			x = pop();
			t = xOPy(x,y,op);
			push(t);
		}
		item = E[i++];
	}
	value = pop();
	printf("The result is %d \n",value);
}