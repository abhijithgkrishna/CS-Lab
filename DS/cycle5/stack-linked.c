#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} * head, *top, *ptr, *new;

void Display()
{
    int data;
    ptr = head->link;
    printf("The Stack is :\n");
    while (ptr != NULL)
    {
        data = ptr->data;
        printf("%d \n", data);
        ptr = ptr->link;
    }
    printf("\n");
}

void push(int item)
{
    new = (struct node *)malloc(sizeof(struct node *));
    new->data = item;
    new->link = head->link;
    head->link = new;
}

int pop()
{
    int item;
    if (head->link != NULL)
    {
        ptr = head->link;
        item = ptr->data;
        head->link = ptr->link;
        free(ptr);
        return item;
    }
    else
    {
        printf("Cannot pop, Stack empty \n");
        return -999;
    }
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
        printf("1. Push \n2. Pop \n3. Exit\n");
        printf("Input option : ");
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
            if (item != -999)
            {
                printf("Popped item is : %d \n", item);
            }
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