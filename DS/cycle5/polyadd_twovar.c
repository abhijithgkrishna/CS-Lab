#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int expx;
    int expy;
    struct node *link;
};
struct node *head1;
struct node *head2;
struct node *head3;
struct node *rear;
struct node *ptr2;
struct node *ptr1;
struct node *temp;
struct node *new;
void main()
{
    int t1, t2, i = 0, j = 0, k = 0;
    printf("Enter no of terms of polynomial 1\n");
    scanf("%d", &t1);
    printf("Enter first polynomial\n");
    for (i = 0; i < t1; i++)
    {
        struct node *ptr1 = (struct node *)malloc(sizeof(struct node));
        if (head1 == NULL)
        {
            scanf("%dx^%dy^%d", &ptr1->coeff, &ptr1->expx, &ptr1->expy);
            ptr1->link = NULL;
            head1 = rear = ptr1;
        }
        else
        {
            rear->link = ptr1;
            rear = ptr1;
            scanf("%dx^%dy^%d", &ptr1->coeff, &ptr1->expx, &ptr1->expy);
            rear->link = NULL;
        }
    }
    printf("First polynomial : ");
    ptr1 = head1;
    for (i = 0; i < t1; i++)
    {
        printf("%d(x^%d)(y^%d) ", ptr1->coeff, ptr1->expx, ptr1->expy);
        if (i != t1 - 1)
            printf("+");
        ptr1 = ptr1->link;
    }
    printf("\n");
    printf("Enter no of terms of polynomial 2\n");
    scanf("%d", &t2);
    printf("Enter second polynomial\n");
    for (i = 0; i < t2; i++)
    {
        struct node *ptr2 = (struct node *)malloc(sizeof(struct node));
        if (head2 == NULL)
        {
            scanf("%dx^%dy^%d", &ptr2->coeff, &ptr2->expx, &ptr2->expy);
            ptr2->link = NULL;
            head2 = rear = ptr2;
        }
        else
        {
            rear->link = ptr2;
            rear = ptr2;
            scanf("%dx^%dy^%d", &ptr2->coeff, &ptr2->expx, &ptr2->expy);
            rear->link = NULL;
        }
    }
    printf("Second polynomial : ");
    ptr2 = head2;
    for (i = 0; i < t2; i++)
    {
        printf("%d(x^%d)(y^%d) ", ptr2->coeff, ptr2->expx, ptr2->expy);
        if (i != t1 - 1)
            printf("+");
        ptr2 = ptr2->link;
    }
    printf("\n");
    i = j = k = 0;
    head3 = (struct node *)malloc(sizeof(struct node));
    temp = head3;
    ptr1 = head1;
    ptr2 = head2;
    while (ptr1 != NULL && ptr2 != NULL)
    {

        new = (struct node *)malloc(sizeof(struct node));
        temp->link = new;
        temp = new;
        temp->link = NULL;
        if (ptr1->expx > ptr2->expx)
        {
            temp->expx = ptr1->expx;
            temp->expy = ptr1->expy;
            temp->coeff = ptr1->coeff;
            ptr1 = ptr1->link;
        }
        else if (ptr1->expx < ptr2->expx)
        {
            temp->expx = ptr2->expx;
            temp->expy = ptr2->expy;
            temp->coeff = ptr2->coeff;
            ptr2 = ptr2->link;
        }
        else
        {
            if (ptr1->expy > ptr2->expy)
            {
                temp->expx = ptr1->expx;
                temp->expy = ptr1->expy;
                temp->coeff = ptr1->coeff;
                ptr1 = ptr1->link;
            }
            else if (ptr1->expy < ptr2->expy)
            {
                temp->expx = ptr2->expx;
                temp->expy = ptr2->expy;
                temp->coeff = ptr2->coeff;
                ptr2 = ptr2->link;
            }
            else
            {
                temp->expx = ptr1->expx;
                temp->expy = ptr1->expy;
                temp->coeff = ptr2->coeff + ptr1->coeff;
                ptr1 = ptr1->link;
                ptr2 = ptr2->link;
            }
        }
    }
    while (ptr1 != NULL)
    {
        new = (struct node *)malloc(sizeof(struct node));
        temp->link = new;
        temp = new;
        temp->coeff = ptr1->coeff;
        temp->expx = ptr1->expx;
        temp->expy = ptr1->expy;
        ptr1 = ptr1->link;
        temp->link = NULL;
    }
    while (ptr2 != NULL)
    {
        new = (struct node *)malloc(sizeof(struct node));
        temp->link = new;
        temp = new;
        temp->coeff = ptr2->coeff;
        temp->expy = ptr2->expy;
        temp->expx = ptr2->expx;
        ptr2 = ptr2->link;
        temp->link = NULL;
    }
    temp = head3->link;
    printf("Resultant polynomial after multiplication\n");
    while (temp->link != NULL)
    {
        if (temp->coeff == 0)
            continue;
        printf("%d(x^%d)(y^%d) + ", temp->coeff, temp->expx, temp->expy);
        temp = temp->link;
    }
    printf("%d(x^%d)(y^%d)", temp->coeff, temp->expx, temp->expy);
}