//Move the smallest element to the end of a single linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
void move_smallest(struct node *start);

int main()
{
	struct node *start= NULL;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list 				: ");
	display(start);
	move_smallest(start);
	printf("After moving smallest ele to end 	: ");
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


void move_smallest(struct node *start)
{
	struct node *cur=NULL, *min_node=NULL;
	int tmp=0;
	if (start == NULL)
		return;
	min_node = start;
	cur = start->link;
	while(cur != NULL)
	{
		if(cur->data < min_node->data)
			min_node = cur;
		cur = cur->link;
	}

	//below logic is shifting smallest value of node to end
	cur = min_node;
	while(cur->link != NULL)
	{
		tmp = cur->data;
		cur->data = cur->link->data;
		cur->link->data = tmp;
		cur = cur->link;
	}

}
