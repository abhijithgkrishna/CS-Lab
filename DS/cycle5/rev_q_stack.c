#include <stdio.h>
#include <stdlib.h>
struct ptr
{
    int data;
    struct ptr *link;
};
struct ptr *head;
struct ptr *front;
struct ptr *rear;
void enqueue(int e)
{
    struct ptr *newptr = (struct ptr *)malloc(sizeof(struct ptr));
    if (front == NULL)
    {
        newptr->data = e;
        newptr->link = NULL;
        front = rear = newptr;
    }
    else
    {
        rear->link = newptr;
        rear = newptr;
        rear->data = e;
        rear->link = NULL;
    }
}
int dequeue()
{
    int item;
    struct ptr *temp;
    if (front == NULL)
        printf("Queue underflow\n");
    else
    {
        item = front->data;
        temp = front;
        front = front->link;
        free(temp);
    }
    return item;
}
void push(int e)
{
    struct ptr *newptr = (struct ptr *)malloc(sizeof(struct ptr));
    if (head == NULL)
    {
        newptr->data = e;
        newptr->link = NULL;
        head = newptr;
    }
    else
    {
        newptr->data = e;
        newptr->link = head;
        head = newptr;
    }
}
int pop()
{
    int item;
    struct ptr *temp;
    if (head == NULL)
        printf("Empty stack\n");
    else
    {
        item = head->data;
        temp = head;
        head = head->link;
        free(temp);
    }
    return item;
}
void display()
{
    int i;
    struct ptr *temp;
    temp = front;
    if (temp == NULL)
        printf("Empty queue\n");
    else
    {
        printf("Queue is \n");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}
void main()
{
    int n = 0, i, e, d;
    char ch = 'Y';
    while (ch == 'y' || ch == 'Y')
    {
        printf("Enter element to be enqueued : ");
        scanf("%d", &e);
        n++;
        enqueue(e);
        printf("Do you you wish to continue(y/n)\n");
        scanf(" %c", &ch);
    }
    display();
    for (i = 0; i < n; i++)
    {
        d = dequeue();
        push(d);
    }
    for (i = 0; i < n; i++)
    {
        d = pop();
        enqueue(d);
    }
    printf("\nReversed ");
    display();
}