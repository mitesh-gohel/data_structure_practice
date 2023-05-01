//Store student data in linked list and calculate no. of pass student if percentage > 40 % than pass
#include<stdio.h>
#include<stdlib.h>


struct student_data
{
	unsigned int roll_no;
	char name[40];
	unsigned int marks[3];
	struct student_data *link;
};


char *my_strcpy(char *dest, char *src);
struct student_data *insert_beg(struct student_data *start, unsigned int roll_no, char *name, unsigned int *marks);

int main()
{
	struct student_data *start = NULL;
	unsigned int choice=0, roll_no=0, marks[3]={0}, i=0, num_of_pass=0;
	char name[40]={0};
	float perc;
	while(1)
	{
		printf("1. Insert student data\n");
		printf("2. Calulate pass student\n");
		printf("3. Quit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 :
				printf("Enter roll no. : ");
				scanf("%d", &roll_no);
				printf("Enter name : \n");
				gets(name);
				for(i=0; i<3; ++i)
				{
					do
					{
						printf("Enter marks of subject no.%d (out of 100) : ", i+1);
						scanf("%d", marks+i);
					}while(marks[i] > 100 && printf("Invalid mark\n"));
				}
				start = insert_beg(start, roll_no, name, marks);
				perc = (marks[0] + marks[1] + marks[2])/3.0;
				printf("Result of roll no.%d = %.2f %%\n", roll_no, perc);
				if(perc > 40)
					++num_of_pass;
				break;
			case 2 :
				printf("%d students passed\n", num_of_pass);
				break;
			case 3 :
				exit(1);
			default :
				printf("Invalid input\n");
		}
	}
	
	return 0;
}

struct student_data *insert_beg(struct student_data *start, unsigned int roll_no, char *name, unsigned int *marks)
{
	struct student_data *new=NULL;
	int i=0;
	new = (struct student_data *)malloc(sizeof(struct student_data));
	new->roll_no = roll_no;
	my_strcpy(new->name, name);
	for(i=0; i<3; ++i)
		*((new->marks)+i) = *(marks+i);
	new->link = start;
	start = new;
	return start;
}

char *my_strcpy(char *dest, char *src)
{
	int i=0;
	for(i=0; *(src+i) != '\0'; ++i)
		*(dest+i) = *(src+i);
	*(dest+i) = '\0';
	return dest;
}


