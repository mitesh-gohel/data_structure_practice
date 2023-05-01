//To find merge point of two single linked lists, which are merged in 'Y' shape

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
void merge_at(struct node **start_1, struct node **start_2, int data);
struct node *find_merge_point(struct node *start1, struct node *start2);

int main()
{
	struct node *start_1= NULL, *start_2=NULL, *merge_point=NULL;
	int merge_data=0;
	printf("For 1st linked list,\n");
	start_1 = create(start_1);
	printf("1st linked list		: ");
	display(start_1);
	printf("For 2nd linked list,\n");
	start_2 = create(start_2);
	printf("2nd linked list 	: ");
	display(start_2);
	printf("Enter a data, where you want to merge 2 linkned list : \n");
	scanf("%d", &merge_data);

	merge_at(&start_1, &start_2, merge_data);
	printf("After merginf in Y shape,\n");
	printf("1st linked list 	: ");
	display(start_1);
	printf("2nd linked list 	: ");
	display(start_2);
	merge_point = find_merge_point(start_1, start_2);
	if(merge_point != NULL)
	{
		printf("Merge point data = %d\n", merge_point->data);
	}
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


void merge_at(struct node **start_1, struct node **start_2, int data)
{
	struct node *cur_1=NULL, *cur_2=NULL, *pre_2=NULL, *del_node=NULL, *next_jump_1=NULL, *next_jump_2=NULL;
	if(*start_1 == NULL  ||  *start_2 == NULL)
		return;
	cur_1 = *start_1;
	while(cur_1 != NULL)
	{
		if(cur_1->data == data)
		{
			//this is merge node
			cur_2 = *start_2;
			while(cur_2 != NULL  &&  cur_2->data != data)
			{
				//find merge node in 2nd list
				pre_2 = cur_2;
				cur_2 = cur_2->link;
			}
			if(cur_2 == NULL)
			{
				printf("%d is not present in 2nd node\n", data);
				return;
			}
			del_node = cur_2; 	//delele ele from 2nd list, because it is alreday there in 1st list
			if(cur_2 == *start_2)
			{
				//if merge node is 1st node of list 2
				*start_2 = cur_1;
			}
			else
			{
				pre_2->link = cur_1;
			}
			cur_2 = cur_2->link;
			free(del_node);
			del_node = NULL;
			while(1)
			{
				//do merge
				//printf("1st ---> : ");
				//display(*start_1);
				//printf("2nd ---> : ");
				//display(*start_2);
				if(cur_1 != NULL  &&  cur_2 != NULL)
				{
					next_jump_1 = cur_1->link;
					cur_1->link = cur_2;
				}
				else
					return;
				if(next_jump_1 == NULL)
					return;
				else
				{
					next_jump_2 = cur_2->link;
					cur_2->link = next_jump_1;
				}
				cur_1 = next_jump_1;
				cur_2 = next_jump_2;
			}
		}
		cur_1 = cur_1->link;
	}
}


struct node *find_merge_point(struct node *start1, struct node *start2)
{
	struct node *cur_1=NULL, *cur_2=NULL;
	cur_1 =  start1;
	while(cur_1 != NULL)
	{
		cur_2 = start2;
		while(cur_2 != NULL)
		{
			if(cur_1 == cur_2)
				return cur_1;
			cur_2 = cur_2->link;
		}
		cur_1 = cur_1->link;
	}
}
