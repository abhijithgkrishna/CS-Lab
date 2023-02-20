#include <stdio.h>
#include <stdlib.h>
typedef struct node
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
            ptr->left = LC;
            BuildTree(LC, value);
        }
        else
        {
            LC = NULL;
            ptr->left = NULL;
            BuildTree(LC, -1);
        }

        printf("Does %d has right node (y/n) : ", item);
        scanf(" %c", &ch);
        if (ch == 'y')
        {
            printf("Enter value of right child : ");
            scanf("%d", &value);
            RC = getnode();
            ptr->right = RC;
            BuildTree(RC, value);
        }
        else
        {
            RC = NULL;
            ptr->right = NULL;
            BuildTree(RC, -1);
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
    root = getnode();
    int rootval;
    printf("enter the value of root : ");
    scanf("%d", &rootval);
    BuildTree(root, rootval);
    Inorder(root);
}
