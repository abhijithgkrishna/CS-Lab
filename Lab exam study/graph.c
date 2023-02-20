#include <stdio.h>
// #include <stack.c>
// #include <queue.c>
int num;
char A[20];
int M[20][20], V[20];

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

int pop()
{
    if (top == -1)
        return -999;
    char temp = S[top];
    top--;
    return temp;
}

int front = -1, rear = -1;
int size = 20;
int Q[20];
void enqueue(int item)
{
    if (rear == size - 1)
        return;
    rear = rear + 1;
    Q[rear] = item;
    if (front == -1)
        front = 0;
}
int dequeue()
{
    int item;
    if (front == -1)
        return 999;
    item = Q[front];
    front++;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
}

void adjmat(char item, int j)
{
    int k;
    for (k = 0; k < num; k++)
    {
        if (A[k] == item)
        {
            break;
        }
    }
    if (k != num)
    {
        M[j][k] = 1;
    }
    else
    {
        printf("Vertex not found");
    }
}

void dispmat()
{
    printf("Adjacency matrix :\n");
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            printf("%d  ", M[i][j]);
        }
        printf("\n");
    }
}

void DFS()
{
    int i, t;
    char s;
    for (i = 0; i < num; i++)
    {
        V[i] = 0;
    }
    printf("Enter starting vertex : ");
    scanf(" %c", &s);
    for (i = 0; i < num; i++)
        if (A[i] == s)
            break;

    printf("DFS \n");
    push(i);
    while (notempty())
    {
        t = pop();
        if (V[t] != 1)
        {
            printf("%c  ", A[t]);
            V[t] = 1;
            for (i = 0; i < num; i++)
            {
                if (M[i][t] == 1 && V[i] == 0)
                {
                    push(i);
                }
            }
        }
    }
}

void BFS()
{
    int i, t;
    char s;
    for (i = 0; i < num; i++)
    {
        V[i] = 0;
    }
    printf("Enter starting vertex : ");
    scanf(" %c", &s);
    for (i = 0; i < num; i++)
        if (A[i] == s)
            break;

    printf("BFS \n");
    printf("%c  ", A[i]);
    V[i] = 1;
    enqueue(i);
    while (front != -1)
    {
        t = dequeue();
        for (i = 0; i < num; i++)
        {
            if (M[t][i] == 1 && V[i] == 0)
            {
                printf("%c  ", A[i]);
                V[i] = 1;
                enqueue(i);
            }
        }
    }
}
void main()
{
    int i = 0, op;
    char ch, item;
    printf("Enter number of vertices : ");
    scanf("%d", &num);
    while (i < num)
    {
        printf("Enter vertex : ");
        scanf(" %c", &A[i]);
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        ch = 'y';
        do
        {
            printf("Does %c has adjacent vertex? : (y/n)", A[j]);
            scanf(" %c", &ch);
            if (ch == 'y')
            {
                printf("\n Enter the adjacent vertex of %c: ", A[j]);
                scanf(" %c", &item);
                adjmat(item, j);
            }
        } while (ch == 'y');
    }
    printf("\n\nGraph menu\n");
    do
    {
        printf("\n1. Adj mat repr \n2. DFS \n3. BFS \n4. Exit\n");
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
            break;
        default:
            printf("Wrong choice!!");
            break;
        }
    } while (op != 4);
}