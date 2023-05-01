//Swap First and last elements of a single linked list
//(i) by exchanging info part
//(ii) by rearranging links

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
void swap_exch(struct node *start);
struct node *swap_rearr(struct node *start);


int main()
{
	struct node *start= NULL;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list 		: ");
	display(start);
	swap_exch(start);
	printf("After 1st time swapping	: ");
	display(start);
	start = swap_rearr(start);
	printf("After 2nd time swapping	: ");
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

void swap_exch(struct node *start)
{
	if(start == NULL  ||  start->link == NULL)
		return;
	struct node *cur=NULL;
	int tmp=0;
	cur = start;
	while(cur->link != NULL)
		cur = cur->link;
	tmp = start->data;
	start->data = cur->data;
	cur->data = tmp;
}


struct node *swap_rearr(struct node *start)
{
	if(start == NULL  ||  start->link == NULL)
		return start;
	struct node *cur=NULL, *pre=NULL;
	cur = start->link;	//start from 2nd element
	pre = cur;
	while(cur->link != NULL)
	{
		pre = cur;
		cur = cur->link;
	}
	cur->link = start->link;
	start->link = NULL;
	pre->link = start;
	start = cur;
	return start;
}
