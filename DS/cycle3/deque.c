// C program to implement double ended queue

#include <stdio.h>
#define MAX 5
#define INV 999

int Q[MAX];
int front = -1;
int rear = -1;

void enqFront(int item)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        Q[front] = item;
    }
    else if (0 == front)
    {
        if (rear == MAX - 1)
        {
            printf("Queue Full, Cannot add \n ");
        }
        else
        {
            front = MAX - 1;
            Q[front] = item;
        }
    }
    else
    {
        if (rear == (front - 1))
        {
            printf("Queue Full, Cannot enqueue");
        }
        else
        {
            front = front - 1;
            Q[front] = item;
        }
    }
}

int deqFront()
{
    int item;
    if (-1 == front)
    {
        printf("Cannot dequeue. Queue empty \n");
        return INV;
    }
    item = Q[front];
    front = (front + 1) % MAX;
    if (front == (rear + 1) % MAX)
    {
        front = -1;
        rear = -1;
    }
    return item;
}

void enqRear(int item)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        Q[rear] = item;
    }
    else if (rear == MAX - 1)
    {
        if (front == 0)
        {
            printf("Queue full, Cannot add item \n");
        }
        else
        {
            rear = 0;
            Q[rear] = item;
        }
    }
    else if (rear == front - 1)
    {
        printf("Queue full, Cannot add item\n");
    }
    else
    {
        rear = rear + 1;
        Q[rear] = item;
    }
}

int deqRear()
{
    int item;
    if (rear == -1)
    {
        printf("Queue empty, cannot dequeue\n");
        return INV;
    }
    else
    {
        item = Q[rear];
        if (0 == rear)
        {
            rear = MAX - 1;
            if (front == 0)
            {
                printf("Queue empty\n ");
                rear = -1;
                front = -1;
            }
        }
        else
        {
            rear = rear - 1;
            if (rear == front -1)
            {
                rear = -1;
                front = -1;
                printf("Queue empty \n");
            }
        }
        return item;
    }
}

void display()
{
    int i;
    printf("The queue is \n");
    i = front;
    while (i != rear)
    {
        printf("%d  ", Q[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", Q[i]);
}

void main()
{
    char opt;
    int val;
    do
    {
        printf("_______________________\n");
        printf("Double ended Queue\n");
        printf("Enqueue front (a) \nDequeue front (b) \nEnqueue rear (c)\nDequeue rear (d) \nQuit (q) \n");
        printf("Enter option : ");
        scanf(" %c", &opt);
        switch (opt)
        {
        case 'a':
            printf("Enter item to enqueue : ");
            scanf("%d", &val);
            enqFront(val);
            display();
            break;
        case 'b':
            val = deqFront();
            if (val != INV)
                printf("\nDequeued item is %d \n", val);
            display();
            break;
        case 'c':
            printf("Enter item to enqueue : ");
            scanf("%d", &val);
            enqRear(val);
            display();
            break;
        case 'd':
            val = deqRear();
            if (val != INV)
                printf("\nDequeued item is %d \n", val);
            display();
            break;
        default:
            break;
        }
    } while (opt != 'q');
}