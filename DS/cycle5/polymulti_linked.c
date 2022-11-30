#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int exp;
    struct node *link;
} * head1, *head2, *head3, *ptr3, *temp, *new, *ptr1, *ptr2, *rear;
void main()
{
    int t1, t2, coeff, exp, i = 0, j = 0, k = 0;
    printf("Enter no of terms of polynomial 1\n");
    scanf("%d", &t1);
    printf("Enter first polynomial\n");
    for (i = 0; i < t1; i++)
    {
        struct node *ptr1 = (struct node *)malloc(sizeof(struct node));
        if (head1 == NULL)
        {
            scanf("%dx^%d", &ptr1->coeff, &ptr1->exp);
            ptr1->link = NULL;
            head1 = rear = ptr1;
        }
        else
        {
            rear->link = ptr1;
            rear = ptr1;
            scanf("%dx^%d", &ptr1->coeff, &ptr1->exp);
            rear->link = NULL;
        }
    }
    printf("First polynomial : ");
    ptr1 = head1;
    for (i = 0; i < t1; i++)
    {
        printf("%d(x^%d) ", ptr1->coeff, ptr1->exp);
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
            scanf("%dx^%d", &ptr2->coeff, &ptr2->exp);
            ptr2->link = NULL;
            head2 = rear = ptr2;
        }
        else
        {
            rear->link = ptr2;
            rear = ptr2;
            scanf("%dx^%d", &ptr2->coeff, &ptr2->exp);
            rear->link = NULL;
        }
    }
    printf("Second polynomial : ");
    ptr2 = head2;
    for (i = 0; i < t2; i++)
    {
        printf("%d(x^%d) ", ptr2->coeff, ptr2->exp);
        if (i != t2 - 1)
            printf("+");
        ptr2 = ptr2->link;
    }
    printf("\n");
    head3 = (struct node *)malloc(sizeof(struct node));
    ptr1 = head1;
    ptr2 = head2;
    temp = head3;
    i = 0;
    while (ptr1 != NULL)
    {
        ptr2 = head2;
        while (ptr2 != NULL)
        {
            ptr3 = (struct node *)malloc(sizeof(struct node));
            temp->link = ptr3;
            ptr3->coeff = ptr1->coeff * ptr2->coeff;
            ptr3->exp = ptr1->exp + ptr2->exp;
            ptr2 = ptr2->link;
            ptr3->link = NULL;
            temp = ptr3;
        }
        ptr1 = ptr1->link;
    }
    ptr1 = head3;
    ptr2 = ptr1->link;
    while (ptr1->link != NULL)
    {
        temp = ptr1;
        while (ptr2 != NULL)
        {
            if (ptr1->exp == ptr2->exp)
            {
                ptr1->coeff = ptr1->coeff + ptr2->coeff;
                temp->link = ptr2->link;
                free(ptr2);
                ptr2 = temp->link;
            }
            else
            {
                temp = ptr2;
                ptr2 = ptr2->link;
            }
        }
        ptr1 = ptr1->link;
        ptr2 = ptr1->link;
    }
    temp = head3->link;
    printf("Resultant polynomial after multiplication : ");
    while (temp->link != NULL)
    {
        if (temp->coeff == 0)
            continue;
        printf("%d(x^%d) + ", temp->coeff, temp->exp);
        temp = temp->link;
    }
    printf("%d(x^%d)", temp->coeff, temp->exp);
}