//Split a single linked list into two lists at a given node

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
void split(struct node *start, struct node **start_2, int data);

int main()
{
	struct node *start=NULL, *start_2=NULL;
	int data=0;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list		: ");
	display(start);
	printf("Enter value at which you want to split linked list : \n");
	scanf("%d", &data);
	split(start, &start_2, data);
	printf("1st linked list 	: ");
	display(start);
	printf("2nd linked list 	: ");
	display(start_2);
	return 0;
}


struct node *create(struct node *start)
{
	int i=0, n=0, data=0;
	struct node *new_node=NULL, *pre=NULL;
	printf("Enter no. of node you want to create\n");
	scanf("%d", &n);

	start = NULL;
	for(i=0; i<n; ++i)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		printf("Enter data :\n");
		scanf("%d", &(new_node->data));
		new_node->link = NULL;
		if(start == NULL)
		{
			start = new_node;
		}
		else
		{
			pre->link = new_node;
		}
		pre = new_node;
	}
	return start;
}


void display(struct node *start)
{
	struct node *cur=NULL;
	cur = start;
	while(cur != NULL)
	{
		printf("%d  ", cur->data);
		cur = cur->link;
	}
	printf("\n");
}


void split(struct node *start, struct node **start_2, int data)
{
	struct node *cur = NULL;
	cur = start;
	while(cur != NULL   &&  cur->data != data)
	{
		cur = cur->link;
	}
	if(cur == NULL)
	{
		*start_2 = NULL;
	}
	else
	{
		*start_2 = cur->link;
		cur->link = NULL;
	}
}
