#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int num;
    char name[15];
    int marks;
    struct node *link;
} *new, *ptr, *temp, *head;

int cnt;

void display();
void insert();
void delete();
void search();
void sort();

void main()
{
    char ch = 'y';
    int c;
    head = (struct node *)malloc(sizeof(struct node));
    while (ch == 'Y' || ch == 'y')
    {
        printf("Enter option \n");
        printf("1.Insert\n2.Delete\n3.Search\n4.Sort\n5.Display\n");
        printf("Enter your choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insert();
            break;
        case 2:
            if (cnt == 0)
                printf("no data in the directory\n");
            else
                delete ();
            break;
        case 3:
            if (cnt == 0)
                printf("no data in the directory\n");
            else
                search();
            break;
        case 4:
            if (cnt == 0)
                printf("no data in the directory\n");
            else
                sort();
            break;
        case 5:
            if (cnt == 0)
                printf("no data in the directory\n");
            else
                display();
            break;
        }
        printf("do you want to access the menu again(y/n)\n");
        scanf(" %c", &ch);
    }
}

void insert()
{
    int no, tmark;
    char str[15];
    printf("Enter the student number\n");
    scanf("%d", &no);
    printf("Enter the student name\n");
    scanf(" %s", str);
    printf("Enter the total marks\n");
    scanf("%d", &tmark);
    new = (struct node *)malloc(sizeof(struct node));
    if (cnt == 0)
    {
        head->link = new;
        new->link = NULL;
    }
    else
    {
        new->link = head->link;
        head->link = new;
    }
    new->num = no;
    strcpy(new->name, str);
    new->marks = tmark;
    cnt++;
}

void delete()
{
    int n, i = 0;
    printf("Enter the number of the student to be deleted\n");
    scanf("%d", &n);
    ptr = head->link;
    while (i < cnt)
    {
        if (ptr->num == n)
            break;
        temp = ptr;
        ptr = ptr->link;
        i++;
    }
    if (i == cnt)
        printf("student not found\n");
    else
    {
        printf("successfully deleted\n");
        if (ptr->link == NULL)
        {
            temp->link = NULL;
            cnt--;
            free(ptr);
        }
        else if (head->link == ptr)
        {
            head->link = ptr->link;
            free(ptr);
            cnt--;
        }
        else
        {
            temp->link = ptr->link;
            free(ptr);
            cnt--;
        }
    }
}

void search()
{
    int n, i = 0;
    printf("Enter the number of student to be searched for\n");
    scanf("%d", &n);
    ptr = head->link;
    while (i < cnt)
    {
        if (ptr->num == n)
            break;
        temp = ptr;
        ptr = ptr->link;
        i++;
    }
    if (i == cnt)
        printf("student not found\n");
    else
    {
        printf("STUDENT DETAILS:\nStudent no:%d\nStudent name:%s\nTotal marks:%d\n", ptr->num, ptr->name, ptr->marks);
    }
}

void display()
{
    ptr = head->link;
    printf("The details of all the students\n\n");
    while (ptr != NULL)
    {
        printf("Student no:%d\nStudent name:%s\nTotal marks:%d\n\n\n", ptr->num, ptr->name, ptr->marks);
        ptr = ptr->link;
    }
}

void sort()
{
    printf("sorted successfully\n");
    int i, j, n, m;
    char s[15];
    struct node *ptr1, *ptr2;
    ptr1 = head->link;
    ptr2 = ptr1->link;
    for (i = 0; i < cnt - 1; i++)
    {
        ptr1 = head->link;
        ptr2 = ptr1->link;
        for (j = 0; j < cnt - i - 1; j++)
        {
            if (ptr1->num > ptr2->num)
            {
                m = ptr2->marks;
                ptr2->marks = ptr1->marks;
                ptr1->marks = m;

                n = ptr2->num;
                ptr2->num = ptr1->num;
                ptr1->num = n;

                strcpy(s, ptr2->name);
                strcpy(ptr2->name, ptr1->name);
                strcpy(ptr1->name, s);
            }

            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
    }
}