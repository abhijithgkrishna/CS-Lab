#include<stdio.h>

void main()
{
	int n,j,flag=0;
	printf("Enter number : \n");
	scanf("%d",&n);
	if (n != 0 && n != 1)
	{
		for ( j = 2; j < n/2; ++j)
		{
			if (0 == n%j)
			{
				flag = -1;
				break;
			}
		}
		if (flag == 0)
		{
			printf("%d is prime \n",n);
		}
		else
			printf("%d is not prime \n",n );
	}
	else
		printf("%d is not prime \n",n );
	
}