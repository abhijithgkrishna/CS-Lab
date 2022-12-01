#include<stdio.h>
#include<stdlib.h>

struct node {
	int data; 
	struct node *llink;
	struct node *rlink;
}*head;

void BuildTree(int item)

void main()
{
	head = (struct node *)malloc(sizeof(struct node *));
	head->data = -1;
	head->llink = NULL;
	head->rlink = NULL;

}