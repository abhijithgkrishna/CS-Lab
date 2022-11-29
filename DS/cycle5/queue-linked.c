#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} * head, *front, *ptr, *new;

void Display()
{
    int data;
    ptr = head->link;
    printf("The Queue is :\n");
    while (ptr != NULL)
    {
        data = ptr->data;
        printf("%d \n", data);
        ptr = ptr->link;
    }
    printf("\n");
}

void Enqueue(int item)
{
    new = (struct node *)malloc(sizeof(struct node *));
    new->data = item;
    new->link = NULL;
    front->link = new;
    front = new;
}

int Dequeue()
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
        printf("Queue empty, Cannot dequeue \n");
        return -999;
    }
}

void main()
{
    int item, opt;
    head = (struct node *)malloc(sizeof(struct node *));
    head->data = -1;
    head->link = NULL;
    front = head;
    do
    {
        printf("\n---------------------------------\n");
        printf("Queue using Linked List \n");
        printf("1. Enqueue \n2. Dequeue \n3. Exit\n");
        printf("Input option : ");
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
            if (item != -999)
            {
                printf("Dequeued item is : %d \n", item);
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