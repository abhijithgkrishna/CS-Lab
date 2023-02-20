#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *LC, *RC, *root;

node *getnode()
{
    return (node *)malloc(sizeof(node));
}
char ch;
int value;

void BuildTree(node *ptr, int item)
{
    if (ptr != NULL)
    {
        ptr->data = item;
        LC = getnode();
        RC = getnode();

        printf("Does %d has left node (y/n): ", item);
        scanf(" %c", &ch);
        if (ch == 'y')
        {
            printf("Enter value of left child : ");
            scanf("%d", &value);
            BuildTree(LC, value);
            ptr->left = LC;
        }
        else
        {
            LC = NULL;
            BuildTree(LC, NULL);
            ptr->left = NULL;
        }

        printf("Does %d has right node (y/n) : ", item);
        scanf(" %c", &ch);
        if (ch == 'y')
        {
            printf("Enter value of right child : ");
            scanf("%d", &value);
            RC = getnode();
            BuildTree(RC, value);
            ptr->right = RC;
        }
        else
        {
            RC = NULL;
            BuildTree(RC, NULL);
            ptr->right = NULL;
        }
    }
}

void Inorder(node *ptr)
{
    if (ptr != NULL)
    {
        Inorder(ptr->left);
        printf("%d ", ptr->data);
        Inorder(ptr->right);
    }
}

void main()
{
    int rootval;
    printf("enter the value of root : ");
    scanf("%d", &rootval);
}
