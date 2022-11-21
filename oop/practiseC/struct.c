#include<stdio.h>

typedef struct 
{
	char name[15];
	int rno,percent;
} Student ;

void main()
{
	Student stu[5];
	int  i;
	printf("STUDENT DETAILS : \n");
	for ( i = 0; i < 5; ++i)
	{
		printf("Enter details of student %d \n",i+1 );
		printf("Enter name :\n");
		scanf("%s",stu[i].name);
		printf("Enter roll no : \n");
		scanf("%d",&stu[i].rno);
		printf("Enter total marks : \n");
		scanf("%d",&stu[i].percent);
		printf("_______________________\n");
	}

	for ( i = 0; i < 5; ++i)
	{
		printf("Details of Student %d \n",i+1);
		printf("Name : %s\n",stu[i].name);
		printf("Roll Number : %d \n",stu[i].rno);
		printf("Total Marks : %d \n",stu[i].percent);
		printf("##############################\n");
	}
}