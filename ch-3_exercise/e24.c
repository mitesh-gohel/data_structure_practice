//make two linked lists one (L2) having the even numbers of L1 and the other (L3) having the odd numbers of L1. Don't chnage list L1

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
void split_list(struct node *start, struct node **odd_start, struct node **even_start);

int main()
{
	struct node *start=NULL, *odd_start=NULL, *even_start=NULL;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list		: ");
	display(start);
	split_list(start, &odd_start, &even_start);
	printf("Odd linked list 	: ");
	display(odd_start);
	printf("Even linked list 	: ");
	display(even_start);
	printf("Original linked list 	: ");
	display(start);
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


void split_list(struct node *start, struct node **odd_start_ptr, struct node **even_start_ptr)
{
	struct node *cur=NULL, *new_node=NULL, *odd_pre=NULL, *even_pre=NULL;
	cur = start;
	while(cur != NULL)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->data = cur->data;
		new_node->link = NULL;
		if(new_node->data % 2  == 1) 	//odd
		{
			if(*odd_start_ptr == NULL)
			{
				*odd_start_ptr = new_node;
			}
			else
			{
				odd_pre->link = new_node;
			}
			odd_pre = new_node;
		}
		else
		{
			if(*even_start_ptr == NULL)
			{
				*even_start_ptr = new_node;
			}
			else
			{
				even_pre->link = new_node;
			}
			even_pre = new_node;
		}
		cur = cur->link;
	}
}
