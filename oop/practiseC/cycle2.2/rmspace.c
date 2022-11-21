#include<stdio.h>

void removech(char str[], int index, int len)
{
	int i;
	for ( i = index; i < len; ++i)
	{
		str[i] = str[i+1];
	}
}

void main()
{
	char sent[100];
	int strlen,i;
	printf("Enter string : \n");
	scanf("%[^\n]",sent);
	for(strlen = 0;sent[strlen]!=0;strlen++);
	for ( i = 0; sent[i] != 0; ++i)
	{
		if (sent[i] == ' ')
		{
			removech(sent,i,strlen);
			strlen--;
		}
	}
	printf("The edited string is %s\n",sent);
}