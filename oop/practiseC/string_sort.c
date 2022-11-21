#define SIZE 10
#include<stdio.h>
#include<string.h>

void main()
{
	int i,j;
	char str[10][50],temp[50];
	for ( i = 0; i < SIZE; ++i)
	{
		printf("Enter string %d \n",i+1);
		scanf("%s",str[i]);
	}
	for ( i = 0; i < SIZE-1; ++i)
	{
		for ( j = 0; j < SIZE-1-i; ++j)
		{
			if (strcmp(str[j],str[j+1])>0)
			{
				strcpy(temp,str[j]);
				strcpy(str[j],str[j+1]);
				strcpy(str[j+1],temp);
			}
		}
	}
	printf("The sorted list is : \n");
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%s\n",str[i]);
	}
}
