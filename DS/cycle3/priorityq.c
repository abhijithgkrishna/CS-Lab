#include <stdio.h>
#define SIZE 5
#define NP 3
#define INV 999

int front[NP];
int rear[NP];
int Q[NP][SIZE];

int enqueue(int item, int p)
{
    if (rear[p] == -1)
    {
        rear[p] = 0;
        front[p] = 0;
        Q[p][rear[p]] = item;
    }
    else if (front[p] != (rear[p] + 1) % SIZE)
    {
        rear[p] = (rear[p] + 1) % SIZE;
        Q[p][rear[p]] = item;
    }
    else
    {
        printf("Queue full, Cannot enqueue \n");
    }
}

int dequeue()
{
    int item, prio = 0;
    while (front[prio] == -1)
    {
        prio = prio + 1;
    }
    if (prio == NP)
    {
        printf("Queue empty \n");
        return INV;
    }
    else
    {
        item = Q[prio][front[prio]];
        front[prio] = (front[prio] + 1) % SIZE;
        if (front[prio] == (rear[prio] + 1) % SIZE)
        {
            front[prio] = -1;
            rear[prio] = -1;
        }
    }
}

void display()
{
    int i = 0, j;
    printf("The queue is\n");
    while (i != NP)
    {
        j = front[i];
        while (j != rear[i])
        {
            printf("%d  ", Q[i][j]);
            j = (j + 1) % SIZE;
        }
        printf("%d\n", Q[i][j]);
        i++;
        printf("\n");
    }
}

void main()
{
    for (int i = 0; i < NP; i++)
    {
        front[i] = -1;
        rear[i] = -1;
    }
    int val, item, p;
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
            printf("Enter priority : ");
            scanf("%d", &p);
            enqueue(val, p);
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