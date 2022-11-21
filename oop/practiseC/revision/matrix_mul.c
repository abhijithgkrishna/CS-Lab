#include<stdio.h>

void main()
{
	int ar1[20][20],ar2[20][20],resar[20][20], m, n, p, q;
	printf("Enter the size of first matrix m and n :\n");
	scanf("%d%d",&m,&n);
	printf("Enter matrix elements :\n");
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d",&ar1[i][j]);
		}
	}
	printf("Enter the size of second matrix m and n :\n");
	scanf("%d%d",&p,&q);
	printf("Enter matrix elements :\n");
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < q; ++j)
		{
			scanf("%d",&ar2[i][j]);
		}
	}
	if(n==p)
	{
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j< q; ++j)
			{
				resar[i][j] = 0;
				for (int k = 0; k < n; ++k)
				{
					resar[i][j] += ar1[i][k]*ar2[k][j];
				}
			}
		}
		printf("The result is :\n");
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < q; ++j)
			{
				printf("%d \t",resar[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("Cannot multiply\n");
	}
}