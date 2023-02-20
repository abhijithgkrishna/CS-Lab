#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
} *root, *LC, *RC;

void BuildTree(struct node *ptr, int item)
{
	char opt = 0;
	int val;
	LC = (struct node *)malloc(sizeof(struct node *));
	RC = (struct node *)malloc(sizeof(struct node *));
	if (ptr != NULL)
	{
		ptr->data = item;
		printf("Node has left child (y/n) : ");
		scanf(" %c", &opt);
		if (opt == 'y' || opt == 'Y')
		{
			ptr->llink = LC;
			printf("Enter value : ");
			scanf("%d", &val);
			BuildTree(LC, val);
		}
		else
		{
			LC = NULL;
			ptr->llink = NULL;
			BuildTree(LC, -1);
		}

		printf("Node has right child (y/n) : ");
		scanf(" %c", &opt);
		if (opt == 'y' || opt == 'Y')
		{
			ptr->rlink = RC;
			printf("Enter value : ");
			scanf("%d", &val);
			BuildTree(RC, val);
		}
		else
		{
			RC = NULL;
			ptr->rlink = NULL;
			BuildTree(RC, -1);
		}
	}
}

void Inorder(struct node *ptr)
{
	printf("\nInorder traversal is  : ");
	if (ptr != NULL)
	{
		Inorder(ptr->llink);
		printf("%d ", ptr->data);
		Inorder(ptr->rlink);
	}
	printf("\n");
}

void Preorder(struct node *ptr)
{
	printf("\nPreorder traversal is  : ");
	if (ptr != NULL)
	{
		printf("%d ", ptr->data);
		Inorder(ptr->llink);
		Inorder(ptr->rlink);
	}
	printf("\n");
}

void Postorder(struct node *ptr)
{
	printf("\nPostorder traversal is  : ");
	if (ptr != NULL)
	{
		Inorder(ptr->llink);
		Inorder(ptr->rlink);
		printf("%d ", ptr->data);
	}
	printf("\n");
}
void main()
{
	root = (struct node *)malloc(sizeof(struct node *));
	root->llink = NULL;
	root->rlink = NULL;
	int val;
	printf("\n\nTREE\n\n");
	printf("Enter value of root : ");
	scanf("%d", &val);
	BuildTree(root, val);
	Inorder(root);
	Preorder(root);
	Postorder(root);
}