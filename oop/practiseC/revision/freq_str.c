#include<stdio.h>

void main()
{
	char str[50],key;
	int i,count=0, len;
	printf("Enter the string : \n");
	scanf(" %s",str);
	printf("Enter key to search \n");
	scanf(" %c",&key);
	for(len = 0;str[len]!=0;len++);
	for ( i = 0; i < len; ++i)
	{
		if (str[i]==key)
		{
			count++;
		}
	}
	printf("%c occured %d times\n",key,count);
}