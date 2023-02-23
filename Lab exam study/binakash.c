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

void BuildTree(node *ptr, int val)
{
    if (ptr != NULL)
    {
        LC = getnode();
        RC = getnode();
        ptr->data = val;
        printf("node %d has left node? ", val);
        scanf(" %c", &ch);
        if (ch == 'y')
        {
            printf("Enter value: ");
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
        printf("node %d has right child ? ", val);
        scanf(" %c", &ch);
        if (ch == 'y')
        {
            printf("Enter vaue ");
            scanf("%d", &value);
            // RC = getnode();
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
    int cal;
    printf("Enter root value ");
    scanf("%d", &cal);
    BuildTree(root, cal);
    Inorder(root);
}