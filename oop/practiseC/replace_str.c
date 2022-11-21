#include<stdio.h>

void main()
{
	int i,j,k =0;
	char str[50], new[50], key, repl[10];
	printf("Enter string : \n");
	scanf("%[^\n]",str);
	printf("Enter character to replace : \n");
	scanf(" %c",&key);
	printf("Enter text to replace %c \n",key);
	scanf("%s",repl);

	for ( i = 0; str[i] != 0; ++i)
	{
		if (str[i] == key)
		{
			for ( j = 0; repl[j]!= 0; ++j)
			{
				new[k++] = repl[j];
			}
		}
		else 
			new[k++] = str[i];
	}
	new[k] = 0;
	printf("The replaced str is ");
	puts(new);
}