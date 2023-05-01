//Program to move a node forward n positions

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
struct node *move_forward(struct node *start, int data, int n);

int main()
{
	struct node *start= NULL;
	int data=0, n=0;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list 	: ");
	display(start);

	printf("Enter data, which you want to move forward : ");
	scanf("%d", &data);
	printf("How many positions, you want to move node forward ? : ");
	scanf("%d", &n);
	start = move_forward(start, data, n);
	printf("After moving 	: ");
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


struct node *move_forward(struct node *start, int data, int n)
{
	struct node *cur=NULL, *move_node=NULL, *pre_move=NULL;	//move_node is node, which need to move forward. 	pre_move is previous of move_node
	int i=0; 
	if(start == NULL  ||  start->link == NULL)
		return start;
	cur = start;
	while(cur != NULL  &&  cur->data != data)
	{
		pre_move = cur;
		cur = cur->link;
	}
	if(cur == NULL)
	{
		printf("%d is not present in linked list\n", data);
		return start;
	}
	move_node = cur;

	while(i != n   &&  cur != NULL)
	{
		i += 1;
		cur = cur->link;
	}
	if(cur == NULL)
	{
		printf("After %d, %d position is not available\n", data, n);
		return start;
	}
	if(move_node == start)
	{
		start = move_node->link;
	}
	else
	{
		pre_move->link = move_node->link;
	}
	move_node->link = cur->link;
	cur->link = move_node;

	return start;
}
