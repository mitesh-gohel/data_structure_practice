//Union of two single linked lists

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
int is_present(struct node *start, int data);
struct node *create_union(struct node *start_1, struct node *start_2);

int main()
{
	struct node *start_1= NULL, *start_2=NULL, *start_3=NULL;
	printf("For 1st linked list,\n");
	start_1 = create(start_1);
	printf("1st linked list : ");
	display(start_1);
	printf("For 2nd linked list,\n");
	start_2 = create(start_2);
	printf("2nd linked list : ");
	display(start_2);

	start_3 = create_union(start_1, start_2);
	printf("Union linked list : ");
	display(start_3);
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


int is_present(struct node *start, int data)
{
	while(start != NULL)
	{
		if(data == start->data)
			return 1;
		start = start->link;
	}
	return 0;
}


struct node *create_union(struct node *start_1, struct node *start_2)
{
	struct node *cur=NULL, *pre=NULL, *start_3=NULL, *new_node=NULL;
	if(start_1 == NULL)
		return NULL;
	cur = start_1;
	while(cur != NULL)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->data = cur->data;
		new_node->link = NULL;
		if(start_3 == NULL)
			start_3 = new_node;
		else
			pre->link = new_node;
		pre = new_node;
		
		cur =  cur->link;
	}
	
	cur = start_2;
	while(cur != NULL)
	{
		if(! is_present(start_3, cur->data))
		{
			new_node = (struct node *)malloc(sizeof(struct node));
			new_node->data = cur->data;
			new_node->link = NULL;
			pre->link = new_node;
			pre = new_node;
		}
		cur = cur->link;
	}
	return start_3;	
}
