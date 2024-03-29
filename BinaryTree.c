#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
} *root, *ptr, *ptr1, *new, *temp;
void Buildtree(struct node *ptr)
{
    char ch1, ch2;
    if (ptr != NULL)
    {
        printf("Left Child for node with data %c? (y/n):", ptr->data);
        scanf(" %c", &ch1);
        if (ch1 == 'y' || ch1 == 'Y')
        {
            new = (struct node *)malloc(sizeof(struct node));
            ptr->lchild = new;
            printf("Enter the data:");
            scanf(" %c", &new->data);
            Buildtree(new);
        }
        else
        {
            ptr->lchild = NULL;
        }
        printf("Right Child for node with data %c? (y/n):", ptr->data);
        scanf(" %c", &ch2);
        if (ch2 == 'y' || ch2 == 'Y')
        {
            new = (struct node *)malloc(sizeof(struct node));
            ptr->rchild = new;
            printf("Enter the data:");
            scanf(" %c", &new->data);
            Buildtree(new);
        }
        else
        {
            ptr->rchild = NULL;
        }
    }
}
void search(struct node *temp, char item)
{
    int flag = 0;
    if (temp != NULL)
    {
        if (temp->data == item)
        {
            ptr1 = NULL;
            ptr = temp;
            flag = 1;
        }
        if (temp->lchild != NULL && flag == 0)
        {
            if (temp->lchild->data == item)
            {
                ptr1 = temp;
                ptr = temp->lchild;
                flag = 1;
            }
        }
        if (temp->rchild != NULL && flag == 0)
        {
            if (temp->rchild->data == item)
            {
                ptr1 = temp;
                ptr = temp->rchild;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            search(temp->lchild, item);
            search(temp->rchild, item);
        }
    }
}
void insert()
{
    char item, ch;
    int i;
    printf("Enter the data of to which new node is to be inserted:");
    scanf(" %c", &item);
    search(root, item);
    if (ptr != NULL)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf(" %c", &new->data);
        new->lchild = NULL;
        new->rchild = NULL;
        printf("Left child or right child?? (l/r):");
        scanf(" %c", &ch);
        if (ch == 'l' || ch == 'L')
        {
            if (ptr->lchild == NULL)
                ptr->lchild = new;
            else
            {
                printf("Left child already exists\n");
                free(new);
            }
        }
        else if (ch == 'r' || ch == 'R')
        {
            if (ptr->rchild == NULL)
                ptr->rchild = new;
            else
            {
                printf("Right child already exists\n");
                free(new);
            }
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
    else
    {
        printf("Item not found\n");
    }
}

void inorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->lchild);
        printf("%c ", ptr->data);
        inorder(ptr->rchild);
    }
}
void preorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        printf("%c ", ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}
void postorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%c ", ptr->data);
    }
}
void succ()
{
    temp = ptr;
    ptr1 = ptr->rchild;
    if (ptr1 != NULL)
    {
        while (ptr1->lchild != NULL)
        {
            temp = ptr1;
            ptr1 = ptr1->lchild;
        }
    }
}
void delete()
{
    char item;
    printf("Enter the data of node to be deleted:");
    scanf(" %c", &item);
    search(root, item);
    if (ptr != NULL)
    {
        if (ptr->lchild == NULL && ptr->rchild == NULL)
        {
            if (ptr1->lchild == ptr)
            {
                ptr1->lchild = NULL;
            }
            else if (ptr1->rchild == ptr)
            {
                ptr1->rchild = NULL;
            }
            free(ptr);
        }
        else if (ptr->lchild == NULL || ptr->rchild == NULL)
        {
            if (ptr1->lchild == ptr)
                if (ptr->lchild == NULL)
                    ptr1->lchild = ptr->rchild;
                else
                    ptr1->lchild = ptr->lchild;
            else if (ptr1->rchild == ptr)
            {
                if (ptr->lchild == NULL)
                    ptr1->rchild = ptr->rchild;
                else
                    ptr1->rchild = ptr->lchild;
            }
            free(ptr);
        }
        else
        {
            succ();
            ptr->data = ptr1->data;
            if (temp->lchild == ptr1)
                if (ptr1->rchild == NULL)
                    temp->lchild = NULL;
                else
                    temp->lchild = ptr1->rchild;
            else if (temp->rchild == ptr1)
                if (ptr1->rchild == NULL)
                    temp->rchild = NULL;
                else
                    temp->rchild = ptr1->rchild;
            free(ptr1);
        }
    }
    else
        printf("Item not found\n");
}
void main()
{
    int k = 1, x;
    char item;
    root = (struct node *)malloc(sizeof(struct node));
    printf("Enter root data:");
    scanf("%c", &root->data);
    root->lchild = NULL;
    root->rchild = NULL;
    Buildtree(root);
    while (k == 1)
    {
        printf("1.Insert node\n2.Inorder\n3.Preorder\n4.Postorder\n5.Delete node\n6.exit\n");
        printf("Choice:");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            insert();
            break;
        case 2:
            inorder(root);
            printf("\n");
            break;
        case 3:
            preorder(root);
            printf("\n");
            break;
        case 4:
            postorder(root);
            printf("\n");
            break;
        case 5:
            delete ();
            break;
        case 6:
            k = 0;
            break;
        default:
            printf("Wrong choice");
        }
    }
}
