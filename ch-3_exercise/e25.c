//Delete alternate nodes(even numbered nodes) from a single linked list.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
void del_alternate(struct node *start);

int main()
{
	struct node *start=NULL;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list			: ");
	display(start);
	del_alternate(start);
	printf("After deleting linked list 	: ");
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


void del_alternate(struct node *start)
{
	struct node *cur=NULL, *del_node;
	cur = start;
	while(cur != NULL  &&  cur->link != NULL)
	{
		del_node = cur->link;
		cur->link = cur->link->link;
		free(del_node);
		del_node = NULL;
		cur = cur->link;
	}
}
