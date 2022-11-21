#include<stdio.h>

void main()
{
	char str[50];
	int len,i,j,flag = 0;
	printf("Enter string : \n");
	scanf("%s",str);
	for(len = 0; str[len]!=0;len++);
	for ( i = 0,j = len-1; i<j; ++i,j--)
	{
		if (str[i]!=str[j])
		{
			flag = -1;
			break;
		}
	}
	if (0==flag)
	{
		printf("%s is a palindrome\n",str );
	}
	else
		printf("Not a palindrome \n");
}