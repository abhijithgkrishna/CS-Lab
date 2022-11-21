#include<stdio.h>

void main()
{
	int a[10], l = 0, r, mid, n, key, flag = 0, i;
	printf("Enter number of elements in the array : \n");
	scanf("%d",&n);
	printf("Enter sorted array \n");
	for ( i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter key to search : \n");
	scanf("%d",&key);
	r = n-1;
	while(l<=r)
	{
		mid = (l+r)/2;		
		if (a[mid] == key)
		{
			printf("Element found at %d \n",mid);
			flag ++;
			break;
		}
		else if (a[mid]>=key)
			r = mid - 1;
		else if (a[mid]<=key)
			l = mid + 1;
	}
	if(flag == 0)
		printf("Item not found\n");
}