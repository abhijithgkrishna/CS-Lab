int top = -1;
int s[20], item;

void push(int item)
{
	if (top == 19)
	{
		printf("Stack full");
	}
	else
	{
		top++;
		s[top] = item;
	}
}

int pop()
{
	char item;
	if (top == -1)
	{
		printf("Stack underflow\n");
	}
	else
	{
		item = s[top];
		top--;
		return item;
	}
}