#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} *root, *ptr, *ptr1, *new,*temp;
void insert(int item)
{
    ptr = root;
    while (ptr != NULL)
    {
        if (item < ptr->data)
        {
            ptr1 = ptr;
            ptr = ptr->lchild;
        }
        else if (item > ptr->data)
        {
            ptr1 = ptr;
            ptr = ptr->rchild;
        }
        else
        {
            printf("Item already present");
            break;
        }
    }
    if (ptr1 != NULL)
    {
        new = (struct node *)malloc(sizeof(struct node));
        new->data = item;
        new->lchild = NULL;
        new->rchild = NULL;
        if (ptr1->data > item)
            ptr1->lchild = new;
        else if (ptr1->data < item)
            ptr1->rchild = new;
    }
}
void inorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->lchild);
        printf("%d ", ptr->data);
        inorder(ptr->rchild);
    }
}
void preorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d ", ptr->data);
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
        printf("%d ", ptr->data);
    }
}
void succ()
{
    temp=ptr;
    ptr1 = ptr->rchild;
    if (ptr1 != NULL)
    {
        while (ptr1->lchild != NULL)
        {
            temp=ptr1;
            ptr1 = ptr1->lchild;
        }
    }
}
void delete (int item)
{
    int item1;
    ptr = root;
    ptr1=NULL;
    while (ptr != NULL)
    {
        if (item < ptr->data)
        {
            ptr1 = ptr;
            ptr = ptr->lchild;
        }
        else if (item > ptr->data)
        {
            ptr1 = ptr;
            ptr = ptr->rchild;
        }
        else
        {
            break;
        }
    }
    if (ptr != NULL)
    {
        if (ptr->lchild == NULL && ptr->rchild == NULL)
        {
            if (ptr1==NULL)
            {
                free(ptr);
                root=NULL;
            }
            else if(ptr1->lchild == ptr)
                ptr1->lchild = NULL;
            else if (ptr1->rchild == ptr)
                ptr1->rchild =NULL;
            free(ptr);
        }
        else if (ptr->lchild != NULL && ptr->rchild != NULL)
        {
            succ();
            ptr->data = ptr1->data;
            if (temp->lchild == ptr1)
                if (ptr1->rchild==NULL)
                    temp->lchild = NULL;
                else
                    temp->lchild = ptr1->rchild;
            else if (temp->rchild == ptr1)
                if (ptr1->rchild==NULL)
                    temp->rchild = NULL;
                else
                    temp->rchild = ptr1->rchild;
            free(ptr1);
        }
        else
        {
            if (ptr1->lchild == ptr)
                if (ptr->lchild == NULL)
                    ptr1->lchild = ptr->rchild;
                else
                    ptr1->lchild = ptr->lchild;
            else
                {
                    if (ptr->lchild == NULL)
                        ptr1->rchild = ptr->rchild;
                    else
                        ptr1->rchild = ptr->lchild;
                }
            free(ptr);
        }
    }
    else
        printf("Item not found");
}
int leaf(struct node *ptr)
{
    if (ptr == NULL)
        return 0;
    if (ptr->lchild == NULL && ptr->rchild == NULL)
        return 1;
    return leaf(ptr->lchild) + leaf(ptr->rchild);
}
void main()
{
    int c = 1, item, x;
    char ch;
    root = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &root->data);
    root->lchild = NULL;
    root->rchild = NULL;
    while (1)
    {
        printf("Are there more elements?(y/n):");
        scanf(" %c", &ch);
        if (ch == 'n' || ch == 'N')
            break;
        printf("Enter data:");
        scanf("%d", &item);
        insert(item);
    }
    c = 1;
    while (c == 1)
    {
        printf("1.Inorder\n2.Preorder\n3.Postorder\n4.Delete node\n5.Number of leaf Nodes\n6.Sort\n7.exit\n");
        printf("Choice:");
        scanf("%d", &x);
        switch (x)
        {
            case 1:
                inorder(root);
                printf("\n");
                break;
            case 2:
                preorder(root);
                printf("\n");
                break;
            case 3:
                postorder(root);
                printf("\n");
                break;
            case 4:
                printf("Enter data of the node to be deleted:");
                scanf("%d", &item);
                delete (item);
                break;
            case 5:
                printf("No of leaf nodes:%d", leaf(root));
                printf("\n");
                break;
            case 6:
                inorder(root);
                printf("\n");
                break;
            case 7:
                c = 0;
                break;
            default:
                printf("Wrong choice");
        }
    }
}
