#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} * head, *top, *ptr, *new;

void Display()
{
}

void push(int item)
{
    new = (struct node *)malloc(sizeof(struct node *));
    new->data = item;
    if (head->link == NULL)
    {
        head->link = new;
        new->link = NULL;
        head = new;
    }
    else
    {
        new->link = head;
        head = new;
    }
}

int pop()
{
}

void main()
{
    head = (struct node *)malloc(sizeof(struct node *));
    head->data = -1;
    head->link = NULL;
    int item, opt;
    do
    {
        printf("\n---------------------------------\n");
        printf("Stack using Linked List \n");
        printf("1. Push \n2.Pop \n3. Exit");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter item to push : ");
            scanf("%d", &item);
            push(item);
            Display();
            break;
        case 2:
            item = pop();
            printf("Popped item is : %d \n", item);
            Display();
            break;
        case 3:
            Display();
            break;

        default:
            break;
        }
    } while (opt != 3);
}