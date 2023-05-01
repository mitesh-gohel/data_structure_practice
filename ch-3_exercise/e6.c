//Swap adjacent elements of single linked list
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
	struct node *cur=NULL, *next=NULL;	// next means, next node where we need to jump
	int tmp=0;
	cur=start;
	while(cur != NULL  &&  cur->link != NULL)
	{
		next = cur->link->link;		//next node = cur node + 2 nodes
		tmp = cur->data;
		cur->data = cur->link->data;
		cur->link->data = tmp;
		cur = next;
	}
}


struct node *swap_rearr(struct node *start)
{
	struct node *cur=NULL, *tmp_node=NULL, *pre=NULL, *next=NULL, *new_start=NULL;	// tmp_node is for swapping nodes
											// pre means, previous node of current node
											// next means, next node where we need to jump
	new_start = start;
	cur = start;
	pre = NULL;	//previous of 1st node NULL
	while(cur != NULL  &&  cur->link != NULL)
	{
		next = cur->link->link; 	//next node = cur node + 2 nodes
		if (pre == NULL) 		//if 1st node
			new_start = cur->link;
		else
			pre->link = cur->link;
		tmp_node = cur->link;
		cur->link = cur->link->link;
		tmp_node->link = cur;
		pre = cur;			//store previous node for next iteration
		cur = next;			//go ahead for next iteration
	}
	return new_start;
}
