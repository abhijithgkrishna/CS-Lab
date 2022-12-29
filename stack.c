int top = -1;
char s[20],item;

void push(char item)
{
	if (top == 19)
	{
		printf("Stack full");
	}
	else
	{
		top ++;
		s[top] = item;
	}
}

char pop()
{
	char item;
	if (top == -1)
	{
		printf("Stack underflow\n");
	}
	else
	{
		item = s[top];
		top --;
		return item;
	}
}