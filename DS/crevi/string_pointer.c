#include<stdio.h>

int strLength(char *s)
{
	int i = 0;
	while(*(s+i++)!='\0');
	return i-1;
}
void strCpy(char *s1, char *s2)
{
	while(*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}
int strComp(char *s1, char *s2)
{
	while(*s1 && *s2)
	{
		if(*s1 != *s2)
			return -1;
		s1++;
		s2++;
	}
	return 0;
}
void strCat(char *s1, char *s2)
{
	while(*s1++);
	s1--;
	while(*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}


void main()
{
	char str1[15] = "apple",str2[15] = "boy",str3[15] = "boy",str4[15] = "cat";
	printf("Length of %s  = %d \n",str1,strLength(str1));
	strCpy(str1,str2);
	printf("After copying, first string is %s \n",str1);
	if (strComp(str2,str3) == 0)
	{
		printf("the strings %s and %s are the same \n",str2,str3);
	}
	else
		printf("the strings %s and %s are the same",str2,str3);
	printf("After concatenating %s and %s we get ",str3,str4);
	strCat(str3,str4);
	printf("%s\n",str3);
}