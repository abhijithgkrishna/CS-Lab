#include<stdio.h>
#include<queue.c>
#include<stack.c>

char G[20];
int M[20][20];
int num;


void adjmat(char item, int j)
{
	int k;
	for (k = 0; k < num; ++k)
	{
		if (G[k] == item)
		{
			break;
		}
		if (k != num)
		{
			M[j][k] = 1;
		}
		else
			printf("Vertex not found\n");
	}

}

void main()
{
	int i = 0,opt = 0, node;
	char ch = 'y', item;
	printf("Graph\n");
	printf("Enter number of vertices : ");
	scanf("%d",&num);
	while(i<num)
	{
		printf("Enter vertex %d of graph : ",i);
		scanf(" %c",&G[i++]);
	}
	for (i = 0 ; i < num; ++i)
	{	
		while(ch == 'y')
		{
			printf("Enter the adjacent vertex of %c \n", G[i]);
			scanf(" %c",item);
			adjmat(item,j);
			printf("Any more adjacent vertex for %c ? (y/n) ",G[i]);
			scanf(" %c",ch);
		}
	}
	do
	{
		printf("Graph operations \n");
		printf("1. Adjacency Matrix \n2. Depth First Search \n3. Breadth First Search \n4. Exit \n");
		printf("Enter option : ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1 :
				displayAdj();
				break;
			case 2 :
				DFS();
				break;
			case 3 :
				BFS();
				break;
			case 4 :
				break;
			default ;
				printf("Wrong choiche\n", );

		}
	}while(opt != 4)

}