#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char data;
    struct node *rlink;
    struct node *llink;
};
struct node *head;
void main()
{
    int n, i, k = 0;
    struct node *temp;
    char str[20], ch;
    printf("Enter string\n");
    scanf(" %s", str);
    n = strlen(str);
    for (i = 0; i < n; i++)
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        if (head == NULL)
        {
            ptr->data = str[i];
            ptr->rlink = NULL;
            ptr->llink = NULL;
            head = ptr;
        }
        else
        {
            temp = head;
            temp->rlink = ptr;
            ptr->data = str[i];
            temp = ptr;
            temp->llink = head;
            temp->rlink = NULL;
            head = ptr;
        }
    }
    temp = head;
    while (temp->llink != NULL)
        temp = temp->llink;
    while (head->llink != NULL)
    {
        if (head->data != temp->data)
            k = 1;
        head = head->llink;
        temp = temp->rlink;
    }
    if (k == 0)
        printf("Palindrome\n");
    else
        printf("Not palindrome\n");
}