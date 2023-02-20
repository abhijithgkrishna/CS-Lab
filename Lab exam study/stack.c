int top = -1;
int SIZE = 20;
char S[20];
int notempty()
{
    if (top != -1)
    {
        return 1;
    }
    return 0;
}
void push(char item)
{
    if (top == SIZE)
    {
        return;
    }
    top++;
    S[top] = item;
}

char pop()
{
    if (top == -1)
        return -999;
    char temp = S[top];
    top--;
    return temp;
}