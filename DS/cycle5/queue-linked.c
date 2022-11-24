#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} * head, *top, *ptr, *new;

struct node *top = NULL;

void Display()
{
}

void Enqueue(int item)
{
}

int Dequeue()
{
}

void main()
{
    int item, opt;
    do
    {
        printf("\n---------------------------------\n");
        printf("Queue using Linked List \n");
        printf("1. Enqueue \n2.Dequeue \n3. Exit");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter item to enqueue : ");
            scanf("%d", &item);
            Enqueue(item);
            Display();
            break;
        case 2:
            item = Dequeue();
            printf("Dequeued item is : %d \n", item);
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