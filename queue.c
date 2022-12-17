char q[20];
int rear = -1, front = -1;

void Enqueue(char item)
{
	if (rear == size -1)
	{
		printf("Queue is full\n");
	}
	else
	{
		if (front == -1)
		{
			front = 0;
		}
		rear = rear+1;
		q[rear] = item;
	}
}

char Dequeue()
{
	char item;
	if (front == -1)
	{
		printf("Queue is empty \n");
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
			front = front -1;
	}
	return item;
}