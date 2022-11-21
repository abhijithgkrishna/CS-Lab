#include<stdio.h>

void main()
{
	char str[50],rev[50];
	int i,len;
	printf("Enter the string : \n");
	scanf(" %s",str);
	for(len = 0;str[len]!=0;len++);
	for (i = 0; i < len; ++i)
	{
		rev[i] = str[len-1-i];
	}
	rev[i] = 0;
	printf("Reverse is %s\n", rev);
}