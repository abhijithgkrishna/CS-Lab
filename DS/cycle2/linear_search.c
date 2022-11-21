#include<stdio.h>

void main()
{
	int a[10], n, key, item, i, flag = 0;
	printf("Enter number of elements : \n");
	scanf("%d",&n);
	printf("Enter the elements ine by one : \n");
	for (i = 0; i < n; ++i)
		scanf("%d",&a[i]);
	printf("Enter element to search : \n");
	scanf("%d",&key);
	for (i = 0; i < n; ++i)
	{
		if (key == a[i])
		{
			printf("Item found at index %d \n", i+1);
			flag ++;
		}
	}
	if (flag == 0)
		printf("Item not present \n");
}