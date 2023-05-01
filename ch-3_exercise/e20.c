//Program to delete duplicates from a unsorted linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
void del_duplicate(struct node *start);

int main()
{
	struct node *start=NULL;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list			: ");
	display(start);
	del_duplicate(start);
	printf("After deleting duplicates 	: ");
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


struct node *insert_sorted(struct node *start, int data)
{
	struct node *new_node=NULL, *cur=NULL;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	if(start == NULL  ||  data <= start->data)
	{
		new_node->link = start;
		start = new_node;
		return start;
	}
	cur= start;
	while(cur->link != NULL  &&  data > cur->link->data)
		cur = cur->link;
	new_node->link = cur->link;
	cur->link = new_node;
	return start;
}


void del_duplicate(struct node *start)
{
	struct node *cur=NULL, *cur_2=NULL, *del_node=NULL;
	cur=start;
	while(cur != NULL  && cur->link != NULL)
	{
		cur_2 = cur;
		while(cur_2->link != NULL)
		{
			if(cur->data == cur_2->link->data)
			{
				del_node = cur_2->link;
				cur_2->link = cur_2->link->link;
				free(del_node);
				del_node = NULL;
			}
			else
				cur_2 = cur_2->link;
		}
		cur = cur->link;
	}
}
