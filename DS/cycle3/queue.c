// C program to implement queue

#include<stdio.h>
#define MAX 5

int Q[MAX];
int fron = -1;
int rear = -1;

void enqueue(int item)
{
	if (rear == MAX-1)
	{
		printf("Queue full, cannot add item \n");
	}
	else if(fron == -1 && rear == -1)
	{
		fron = 0;
		rear = 0;
		Q[rear] = item;
	}
	else
	{
		rear++;
		Q[rear] = item;
	}
}
void dequeue()
{
	if (fron == -1)
	{
		printf("Queue Empty\n");
	}
	else
	{
		printf("Dequeued item : %d \n",Q[fron++]);
		if (fron == rear+1)
		{
			fron = -1;
			rear = -1; 
		}
	}
}
void printQ()
{	if (fron == rear+1)
	{
		printf("Current Queue :\n");
		printf("Empty\n");
	}
	else
	{
		printf("Current Queue : \n");
		for (int i = fron; i <= rear; ++i)
		{
			printf("%d ",Q[i]);
		}
	}
}

void main()
{
	int x;
	char opt;
	do
	{
		printf("Enqueue (e) \nDequeue (d) \nExit (q)\n");
		printf("Enter option : ");
		scanf(" %c",&opt);
		if (opt == 'e')
		{
			printf("Enter item to enqueue :\n");
			scanf("%d",&x);
			enqueue(x);
			printQ();
		}
		else if (opt == 'd')
		{
			dequeue();
			printQ();
		}
		printf("\n**********************************\n\n");

	}while(opt != 'q');
}