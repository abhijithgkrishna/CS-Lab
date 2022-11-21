#include<stdio.h>
#include<string.h>
#define MAX 20
#define INVAL '`'

char S[MAX];
int TOP = -1;

void push(char ch)
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
char pop()
{
	char temp;
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

int isOperand(char ch)
{
	return (ch >= 'A' && ch <= 'Z')||(ch >= 'a' && ch <= 'z');
}
int ISP(char ch)
{
	int isp;
	switch(ch)
	{
		case '+':
		case '-':
			isp = 2;
			break;
		case '*':
		case '/':
			isp = 4;
			break;
		case '^':
			isp = 5;
			break;
		case '(':
			isp = 0;
			break;
		case ')':
			isp = -1;
			break;
		default :
			break;
	}
	return isp;
}

int ICP(char ch)
{
	int icp;
	switch(ch)
	{
		case '+':
		case '-':
			icp = 1;
			break;
		case '*':
		case '/':
			icp = 3;
			break;
		case '^':
			icp = 6;
			break;
		case '(':
			icp = 7;
			break;
		case ')':
			icp = 0;
			break;
		default :
			break;
	}
	return icp;
}



void main()
{
	int i=0;
	char E[20],x,item;
	printf("Enter expression \n");
	scanf("%s",E);
	strcat(E,")");
	push('(');
	while(TOP>=0)
	{
		item = E[i++];
		x = pop();
		if (isOperand(item))
		{
			printf("%c",item);
			push(x);
		}
		else if (')' == item)
		{
			while(x != '(')
			{
				printf("%c",x );
				x = pop();
			}
		}
		else if (ISP(x)>=ICP(item))
		{
			while(ISP(x)>=ICP(item))
			{
				printf("%c",x);
				x = pop();
			}
			push(x);
			push(item);
		}
		else if (ISP(x)<ICP(item))
		{
			push(x);
			push(item);
		}
	}
	
	
}