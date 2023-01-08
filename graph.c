#define size 20
#include <stdio.h>
#include <stdlib.h>
char A[20], S[20], q[20];
int M[20][20], V[20], n, top = -1, front = -1, rear = -1;
void Enqueue(char item)
{
	if (rear == size - 1)
	{
		printf("Queue is full");
	}
	else
	{
		if (front == -1)
		{
			front = 0;
		}
		rear = rear + 1;
		q[rear] = item;
	}
}
char Dequeue()
{
	char item;
	if (front == -1)
	{
		printf("Queue is empty");
	}
	else
	{
		item = q[front];
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front = front + 1;
		}
	}
	return item;
}
void push(char item)
{
	if (top == size - 1)
		printf("Stack Overflow");
	else
	{
		top++;
		S[top] = item;
	}
}
char pop()
{
	char item;
	if (top == -1)
		printf("Stack Underflow");
	else
	{
		item = S[top];
		top--;
		return item;
	}
}
void adjmat(char item, int j)
{
	int k;
	for (k = 0; k < n; k++)
	{
		if (A[k] == item)
			break;
	}
	if (k != n)
		M[j][k] = 1;
	else
		printf("Vertex not found");
}
void dispmat()
{
	int j, k;
	printf("Adjacency Matrix:\n");
	for (j = 0; j < n; j++)
	{
		for (k = 0; k < n; k++)
		{
			printf("%d ", M[j][k]);
		}
		printf("\n");
	}
}
void DFS()
{
	int i, j;
	char t, s;
	for (i = 0; i < n; i++)
		V[i] = 0;
	printf("Enter the starting vertex: ");
	scanf(" %c", &s);
	for (i = 0; i < n; i++)
	{
		if (A[i] == s)
			break;
	}
	printf("DFS:");
	push(i);
	while (top != -1)
	{
		t = pop();
		if (V[t] != 1)
		{
			printf("%c\t", A[t]);
			V[t] = 1;
			for (i = 0; i < n; i++)
			{
				if (M[t][i] == 1 && V[i] == 0)
				{
					push(i);
				}
			}
		}
	}
}

void BFS()
{
	int i, j;
	char t, s;
	for (i = 0; i < n; i++)
		V[i] = 0;
	printf("Enter the starting vertex: ");
	scanf(" %c", &s);
	for (i = 0; i < n; i++)
	{
		if (A[i] == s)
			break;
	}
	printf("BFS:");
	printf(" %c\t", A[i]);
	V[i] = 1;
	Enqueue(i);
	while (front != -1)
	{
		t = Dequeue();
		for (i = 0; i < n; i++)
		{
			if (M[t][i] == 1 && V[i] == 0)
			{
				printf(" %c\t", A[i]);
				V[i] = 1;
				Enqueue(i);
			}
		}
	}
}
void main()
{
	char ch, item;
	int i = 0, j = 0, c = 1, op;
	printf("Enter the number of vertices : ");
	scanf("%d", &n);
	while (i < n)
	{
		printf("Enter vertex : ");
		scanf(" %c", &A[i]);
		i++;
	}
	for (j = 0; j < i; j++)
	{
		ch = 'y';
		while (ch == 'y' || ch == 'Y')
		{
			printf("\nEnter the adjacent vertex of %c: ", A[j]);
			scanf(" %c", &item);
			adjmat(item, j);
			printf("Does %c have adjacent vertex: ", A[j]);
			scanf(" %c", &ch);
		}
	}
	while (c == 1)
	{
		printf("\n1.Adjacent Matrix Representation\n2.Depth First Search\n3.Breadth First Search\n4.exit");
		printf("\nEnter your choice: ");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			dispmat();
			break;
		case 2:
			DFS();
			break;
		case 3:
			BFS();
			break;
		case 4:
			c = 0;
			break;
		default:
			printf("Invalid Choice");
		}
	}
}