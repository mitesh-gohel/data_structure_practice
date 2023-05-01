//Remove the last node of the list and insert it in the beginning, without changing info part of any node

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
struct node *move_node(struct node *start);

int main()
{
	struct node *start= NULL;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list			: ");
	display(start);

	start = move_node(start);
	printf("After moving 1st node to end	: ");
	display(start);
	return 0;
}


struct node *create(struct node *start)
{
	int i=0, n=0;
	struct node *new_node=NULL, *cur=NULL;
	printf("Enter no. of node you want to create\n");
	scanf("%d", &n);

	start = NULL;
	cur = start;
	for(i=0; i<n; ++i)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		printf("Enter data :\n");
		scanf("%d", &(new_node->data));
		new_node->link = NULL;

		if(cur == NULL)	//if 1st node
		{
			start = new_node;
			cur = new_node;
		}
		else
		{
			cur->link = new_node;
			cur = cur->link;
		}
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


struct node *move_node(struct node *start)
{
	struct node *cur=NULL, *pre=NULL;
	if(start == NULL  ||  start->link == NULL)
		return start;
	cur = start->link;
	pre = start;
	while(cur->link != NULL)
	{
		pre = cur;
		cur = cur->link;
	}
	pre->link = NULL;
	cur->link = start;
	start = cur;
	return start;
}
