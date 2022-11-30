#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int rno;
    char name;
    int total_mark;
    struct node *link;
} * head, *ptr, *new, *temp;

void AddStu(int roll, char name, int mark)
{
    new = (struct node *)malloc(sizeof(struct node *));

    new->rno = roll;
    new->name = name;
    new->total_mark = mark;
    new->link = head->link;
    head->link = new;
}
void Delete(int roll)
{
    ptr = head->link;
    while (ptr->rno != roll)
    {
        temp = ptr;
        ptr = ptr->link;
    }
    temp->link = ptr->link;
    free(ptr);
}
void Search(int roll)
{
    ptr = head->link;
    while (ptr->rno != roll)
    {
        ptr = ptr->link;
    }
    if (ptr == NULL)
    {
        printf("Entry does not exist\n");
    }
    else
    {
        printf("Roll Number : %d \n", ptr->rno);
        printf("Name is : %c\n", ptr->name);
        printf("Total marks : %d\n", ptr->total_mark);
    }
}
// void Sort()
// {
// }
void Display()
{
    ptr = head->link;
    printf("The list is \n");
    while (ptr->link != NULL)
    {
        printf("Roll no :\n");
        printf("Name : %c\n", ptr->name);
        printf("Total Marks : %d", ptr->total_mark);
        printf("\n");
        ptr = ptr->link;
    }
}

void main()
{
    head = (struct node *)malloc(sizeof(struct node *));
    head->link = NULL;
    head->name = 'z';
    head->rno = 0;
    head->total_mark = 0;
    int opt, rno, mark;
    char name;
    do
    {
        printf("\n-------------------------------\n");
        printf("Student Details Menu \n");
        printf("1. Insert \n2. Delete \n3. Search \n4. Sort \n5. Exit\n");
        printf("Enter Option : ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter roll number of student : ");
            scanf("%d", &rno);
            printf("Enter name of student : ");
            scanf(" %c", &name);
            printf("Enter total marks : ");
            scanf("%d", &mark);
            AddStu(rno, name, mark);
            Display();
            break;
        case 2:
            printf("Enter roll number to delete");
            scanf("%d", &rno);
            Delete(rno);
            printf("Deleted");
            Display();
            break;
        case 3:
            printf("Enter roll number to search : ");
            scanf("%d", &rno);
            Search(rno);
            // Display();
            break;
            // case 4:
            //     Sort();
            //     Display();

        default:
            break;
        }
    } while (opt != 5);
}