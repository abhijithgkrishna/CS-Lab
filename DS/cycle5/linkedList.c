#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
} *head, *ptr, *new, *temp;

void Display()
{

	printf("The linked list is : \n");
	ptr = head->link;
	while (ptr != NULL)
	{
		printf("%d  ", ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}

void addFront(int item)
{
	new = (struct node *)malloc(sizeof(struct node *));
	new->data = item;
	new->link = head->link;
	head->link = new;
}

void addEnd(int item)
{
	new = (struct node *)malloc(sizeof(struct node *));
	ptr = head;
	while (ptr->link != NULL)
	{
		ptr = ptr->link;
	}
	ptr->link = new;
	new->data = item;
	new->link = NULL;
}

void addSpecific(int item, int key)
{
	new = (struct node *)malloc(sizeof(struct node *));
	ptr = head;
	while (ptr->data != key)
	{
		ptr = ptr->link;
		if (ptr->link == NULL)
		{
			printf("Key not found \n");
			return;
		}
	}
	new->link = ptr->link;
	new->data = item;
	ptr->link = new;
}

void deleteFront()
{
	if (head->link != NULL)
	{
		temp = head->link;
		head->link = temp->link;
		free(temp);
	}
	else
		printf("No linked list\n");
}

void deleteEnd()
{
	if (head->link != NULL)
	{
		ptr = head;
		while (ptr->link != NULL)
		{
			temp = ptr;
			ptr = ptr->link;
		}
		temp->link = NULL;
		free(ptr);
	}
	else
		printf("No linked list\n");
}

void deleteSpecified(int key)
{
	ptr = head;
	while (ptr->data != key)
	{
		temp = ptr;
		ptr = ptr->link;
	}
	temp->link = ptr->link;
	free(ptr);
}
void main()
{
	head = (struct node *)malloc(sizeof(struct node *));
	head->data = -1;
	head->link = NULL;
	int opt = 0;
	int item, key;
	do
	{
		printf("\n\n-------------------------------------------------\n");
		printf("Linked list operations\n");
		printf("Enter option : \n");
		printf("1. Insert at beginning \n2. Insert at end\n3. Insert at specified position \n4. Delete from beginning \n5. Delete from end \n6. Delete from specified position \n7. Exit\n");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			printf("Item to input : \n");
			scanf("%d", &item);
			addFront(item);
			Display();
			break;
		case 2:
			printf("Item to input : \n");
			scanf("%d", &item);
			addEnd(item);
			Display();
			break;
		case 3:
			printf("Item to input : \n");
			scanf("%d", &item);
			printf("Enter key which is the specified position \n");
			scanf("%d", &key);
			addSpecific(item, key);
			Display();
			break;
		case 4:
			deleteFront();
			Display();
			break;
		case 5:
			deleteEnd();
			Display();
			break;
		case 6:
			printf("Enter value of node to delete : ");
			scanf("%d", &key);
			deleteSpecified(key);
			Display();
			break;
		default:
			break;
		}
	} while (opt != 7);
}
