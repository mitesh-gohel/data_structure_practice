//split a single linked list into two lists such that alternate nodes go to different lists. 

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
void split(struct node *start, struct node **start_2);

int main()
{
	struct node *start=NULL, *start_2=NULL;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list		: ");
	display(start);
	split(start, &start_2);
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


void split(struct node *start, struct node **start_2)
{
	struct node *cur_1=NULL, *cur_2=NULL;
	cur_1 = start;
	while(cur_1 != NULL  &&  cur_1->link !=NULL)
	{
		if(cur_1 == start) //for 1st node
		{
			*start_2 = cur_1->link;
			cur_2 = *start_2;
		}
		else
		{
			cur_2->link = cur_1->link;
			cur_2 = cur_2->link;
		}
		cur_1->link = cur_1->link->link;
		cur_2->link = NULL;
		cur_1 = cur_1->link;
	}
}
