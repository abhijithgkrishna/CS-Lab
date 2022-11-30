#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *link;
} * head, *top, *ptr, *new;

void push(int item)
{
    new = (struct stack *)malloc(sizeof(struct stack *));
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