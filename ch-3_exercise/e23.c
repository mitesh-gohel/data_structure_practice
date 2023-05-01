/*
Delete all the nodes having negative numbers in info part from the list L1 and insert them into list L2 
Delete all the nodes having positive numbers in info part from the list L1 and insert them into list L3. 
No new nodes to be allocated.
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
void split_list(struct node **start, struct node **neg_start, struct node **pos_start);

int main()
{
	struct node *start=NULL, *neg_start=NULL, *pos_start=NULL;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list		: ");
	display(start);
	split_list(&start, &neg_start, &pos_start);
	printf("Negative linked list 	: ");
	display(neg_start);
	printf("Positive linked list 	: ");
	display(pos_start);
	printf("Original linked list 	: ");
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


void split_list(struct node **start_ptr, struct node **neg_start_ptr, struct node **pos_start_ptr)
{
	struct node *cur_1=NULL, *neg_pre=NULL, *pos_pre=NULL;
	cur_1 = *start_ptr;
	while(cur_1 != NULL)
	{
		if(cur_1->data < 0)
		{
			if(*neg_start_ptr == NULL)
			{
				*neg_start_ptr = cur_1;

			}
			else
			{
				neg_pre->link = cur_1;
			}
			neg_pre = cur_1;	
		}
		else
		{
			if(*pos_start_ptr == NULL)
			{
				*pos_start_ptr = cur_1;
			}
			else
			{
				pos_pre->link = cur_1;
			}
			pos_pre = cur_1;
		}
		*start_ptr = cur_1->link;	//remove 1st node from original list
		cur_1->link = NULL;
		cur_1 = *start_ptr;		//go ahead
	}
}
