//Program to free all nodes of a single linked list 

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
void destroy(struct node *start);

int main()
{
	struct node *start=NULL;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list 	: ");
	display(start);
	destroy(start);
	start = NULL;
	printf("After deleting 	: ");
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


void destroy(struct node *start)
{
	struct node *del_node=NULL;
	while(start != NULL)
	{
		del_node = start;
		start = start->link;
		free(del_node);
		del_node = NULL;
	}
}
