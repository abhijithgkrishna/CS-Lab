#include<stdio.h>
#include<string.h>

int isIn(char s[],int n,char key)
{
	for (int i = 0; i < n; ++i)
	{
		if(s[i] == key)
			return 0;
	}
	return -1;
}
void clear(char s[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		s[i] = '\0';
	}
}

void main()
{
	int len = 0, strlen = 0, i = 0,k,j,m;
	char str[50],temp[20],longer[20];
	printf("Enter the string : \n");
	scanf("%s",str);
	for(;str[strlen]!='\0';strlen++);

	while(i<strlen)
	{
		k = 0;
		clear(temp,20);
		temp[k] = str[i];
		for (j = i+1;isIn(temp,20,str[j]) == -1;j++)
		{
			temp[++k] = str[j];
		}
		if(len<k)
		{
			len = k;
			for (m = 0; m < len+1; ++m)
			{
				longer[m] = temp[m];
			}
		}
		i++;
	}
	printf("Length of longest substring is %d \n",len+1);
	printf("Longest substring is %s \n",longer);

}