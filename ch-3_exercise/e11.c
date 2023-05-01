//Delete all nodes that have value n 

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
struct node *del(struct node *start, int data);

int main()
{
	struct node *start= NULL;
	int n=0;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list 	: ");
	display(start);

	printf("Enter number, which you want to delete from list : ");
	scanf("%d", &n);
	start = del(start, n);
	printf("After deleting : ");
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


struct node *del(struct node *start, int data)
{
	struct node *cur=NULL, *del_node=NULL;
	if(start == NULL)
		return start;
	while(start != NULL  &&  start->data == data)
	{
		del_node = start;
		start = start->link;
		free(del_node);
		del_node = NULL;
	}
	if(start == NULL)
		return start;
	cur = start;
	while(cur->link != NULL)
	{
		if(cur->link->data == data)
		{
			del_node = cur->link;
			cur->link = cur->link->link;
			free(del_node);
			del_node = NULL;
		}
		else
		{
			cur = cur->link;
		}
	}
	return start;
}
