#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;
int size = 10;
node *a[30];
node *new;
node *temp;
node *ptr;
int b[10];
void insert1(int val);
void display();
void insert2(int val);
void dis();
void insert1(int val)
{
    new = (node *)malloc(sizeof(node));
    new->data = val;
    new->link = NULL;
    int k = val % size;
    if (a[k] == NULL)
    {
        a[k] = new;
    }
    else
    {
        temp = a[k];
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
    }
}
void display()
{
    int i;
    for (i = 0; i < size; i++)
    {
        ptr = a[i];
        printf("%d :", i);
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}

void insert2(int val)
{
    int k = val % size;
    if (b[k] == -1)
    {
        b[k] = val;
    }
    else
    {
        int i;
        int f = 0;
        for (i = k + 1; i < size; i++)
        {
            if (b[i] == -1)
            {
                b[i] = val;
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            for (i = 0; i < k; i++)
            {
                if (b[i] == -1)
                {
                    b[i] = val;
                    break;
                }
            }
        }
    }
}
void dis()
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (b[i] == -1)
        {
            printf("%d :\n", i);
        }
        else
        {
            printf("%d : %d\n", i, b[i]);
        }
    }
}
void main()
{
    int i, n, x, choice;
    for (i = 0; i < size; i++)
    {
        b[i] = -1;
    }
    printf("Enter the number of inputs: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the input: ");
        scanf("%d", &x);
        insert1(x);
        insert2(x);
    }
    printf("\nChaining method\n");
    display();
    printf("\nLinear Probing\n");
    dis();
}