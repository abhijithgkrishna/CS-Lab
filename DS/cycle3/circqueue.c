#include <stdio.h>
#define SIZE 5
#define INV 999

int CQ[SIZE];
int front = -1;
int rear = -1;

void enqueue(int item)
{
    if (rear == -1)
    {
        rear = 0;
        front = 0;
        CQ[rear] = item;
    }
    else if (front != (rear + 1) % SIZE)
    {
        rear = (rear + 1) % SIZE;
        CQ[rear] = item;
    }
    else
    {
        printf("Queue full cannot enqueue \n");
    }
}

int dequeue()
{
    int item;
    if (front == -1)
    {
        printf("cannot dequeue, queue empty\n");
        return INV;
    }
    else
    {
        item = CQ[front];
        front = (front + 1) % SIZE;
        if (front == (rear + 1) % SIZE)
        {
            front = -1;
            rear = -1;
        }
    }
}

void display()
{
    int i;
    printf("The queue is \n");
    i = front;
    while (i != rear)
    {
        printf("%d  ", CQ[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", CQ[i]);
}

void main()
{
    int val, item;
    char opt;
    do
    {
        printf("\n_______________________________________________\n");
        printf("Queue\n");
        printf("1. Enqueue (e)\n2. Dequeue (d) \n3. Exit (q)\n");
        printf("Enter option : ");
        scanf(" %c", &opt);
        switch (opt)
        {
        case 'e':
            printf("Enter item to enqueue : ");
            scanf("%d", &val);
            enqueue(val);
            display();
            break;
        case 'd':
            item = dequeue();
            if (item != INV)
            {
                printf("Dequeued item is %d\n", item);
            }
            display();
            break;
        default:
            break;
        }
    } while (opt != 'q');
}