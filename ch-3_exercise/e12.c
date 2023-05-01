//Print a list according to other list. 1st list is sorted single linked list. 2nd list is single linked list. Ex. if 1st sorted linked list is 2->4->1->5>1->3 then, program should print 2nd, 4th, 1st, 5th, 1st, 3rd ele of 2nd linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
struct node *create_sorted(struct node *start);
struct node *insert_sorted(struct node *start, int data);
void display(struct node *start);
void print_ele(struct node *start_1, struct node *start_2);

int main()
{
	struct node *start_1= NULL, *start_2=NULL;
	int n=0;
	printf("For 1st sorted linked list,\n");
	start_1 = create_sorted(start_1);
	printf("1st linked list : ");
	display(start_1);
	printf("For 2nd linked list,\n");
	start_2 = create(start_2);
	printf("2nd linked list : ");
	display(start_2);

	printf("Result : ");
	print_ele(start_1, start_2);
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


struct node *create_sorted(struct node *start)
{
	int n=0, i=0, data;
	printf("Enter no. of node, you want to create  in sorted linked list : ");
	scanf("%d", &n);
	if(n == 0)
		return NULL;
	start = NULL;
	for(i=0; i<n; ++i)
	{
		printf("Enter data : ");
		scanf("%d", &data);
		start = insert_sorted(start, data);
	}
	return start;
}


struct node *insert_sorted(struct node *start, int data)
{
	struct node *cur=NULL, *new_node=NULL, *pre=NULL;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	if(start == NULL  ||  data <= start->data)
	{
		new_node->link = start;
		start = new_node;
		return start;
	}
	cur = start->link;
	pre = start;
	while(cur != NULL  &&  data > cur->data)
	{
		pre = cur;
		cur = cur->link;
	}
	pre->link = new_node;
	new_node->link = cur;
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


void print_ele(struct node *start_1, struct node *start_2)
{
	struct node *cur_1=NULL, *cur_2=NULL;
	int target_num, ele_num = 1;
	cur_1 = start_1;
	cur_2 = start_2;
	while(cur_1 != NULL)
	{
		target_num = cur_1->data;
		while(ele_num != target_num  &&  cur_2 != NULL)
		{
			ele_num += 1;
			cur_2 = cur_2->link;
		}
		if(cur_2 != NULL)
		{
			printf("%d ", cur_2->data);
		}
		else
		{
			printf("\nError : Only %d element available in 2nd linked list\n", ele_num-1);
			return;
		}

		cur_1 = cur_1->link;
	}
	printf("\n");
}
