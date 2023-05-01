//Swap Adjacent elements in a double linked list by rearraning list

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *pre;
	struct node *next;
};

struct node *create(struct node *start);
void display(struct node *start);
struct node *swap_rearr(struct node *start);


int main()
{
	struct node *start= NULL;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list 	: ");
	display(start);
	start = swap_rearr(start);
	printf("After swapping	: ");
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
		new_node->next = NULL;

		if(cur == NULL)	//if 1st node
		{
			new_node->pre = NULL;
			start = new_node;
			cur = new_node;
		}
		else
		{
			new_node->pre = cur;
			cur->next = new_node;
			cur = cur->next;;
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
		cur = cur->next;
	}
	printf("\n");
}


struct node *swap_rearr(struct node *start)
{
	struct node *cur=NULL, *next_jump=NULL, *tmp_node=NULL;
	if(start == NULL  ||  start->next == NULL) //if list is empty  OR  only 1 element in list
		return start;

	cur = start;
	while(cur != NULL  && cur->next != NULL)
	{
		next_jump = cur->next->next; 	//next jump is : cur = cur + 2 nodes
		if(start == cur) //if 1st node
			start = cur->next;
		else
			cur->pre->next = cur->next;
		tmp_node = cur->next;
		cur->next = cur->next->next;
		tmp_node->next = cur;
		tmp_node->pre = cur->pre; 
		cur->pre = tmp_node;
		if(next_jump !=  NULL)
			next_jump->pre =  cur;
		cur = next_jump;
	}
	return start;
}
