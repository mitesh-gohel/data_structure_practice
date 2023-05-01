//Delete a node when only pointer to it is given 

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
void delete(struct node *ptr);

int main()
{
	struct node *start=NULL, *cur=NULL;
	int data=0;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list 	: ");
	display(start);

	printf("Enter data, which you want to delete from linked list : ");
	scanf("%d", &data);
	cur = start;
	while(cur != NULL)
	{
		if(cur->data == data)
		{
			delete(cur);
			break;
		}
		cur = cur->link;
	}
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


void delete(struct node *ptr)
{
	struct node *tmp_node=NULL;
	int tmp;
	if(ptr == NULL)
		return;
	if(ptr->link == NULL)
	{
		printf("Can't delete last node without info about start node of linked list\n");
		return;
	}

	tmp = ptr->data;
	ptr->data = ptr->link->data;
	ptr->link->data = tmp;
	tmp_node = ptr->link;
	ptr->link = ptr->link->link;
	free(tmp_node);
	tmp_node = NULL;
}
