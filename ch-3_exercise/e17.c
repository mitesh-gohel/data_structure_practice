//Functions to insert a node just before and just after a node pointed to by a pointer p, without using the pointer start

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
struct node *get_ptr(struct node *start, int data);
void insert_after(struct node *ptr, int data);
void insert_before(struct node *ptr, int data);

int main()
{
	struct node *start=NULL, *ptr=NULL;
	int data=0, new_data=0;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list 	: ");
	display(start);

	printf("Enter data, which you want to insert : ");
	scanf("%d", &new_data);
	printf("Enter value, before which you want to insert data\n");
	scanf("%d", &data);
	ptr = get_ptr(start, data);
	if(ptr == NULL)
		return 0;
	insert_before(ptr, new_data);
	printf("After inserting	: ");
	display(start);

	printf("Enter data, which you want to insert : ");
	scanf("%d", &new_data);
	printf("Enter value, after which you want to insert data\n");
	scanf("%d", &data);
	ptr = get_ptr(start, data);
	if(ptr == NULL)
		return 0;
	insert_after(ptr, new_data);
	printf("After inserting	: ");
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


struct node *get_ptr(struct node *start, int data)
{
	while(start != NULL)
	{
		if(start->data == data)
		{
			return start;
		}
		start = start->link;
	}
	if(start == NULL)
	{
		printf("%d is not present in linked list\n", data);
		return NULL;
	}
}


void insert_after(struct node *ptr, int data)
{
	struct node *new_node=NULL;
	if(ptr == NULL)
		return;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->link = ptr->link;
	ptr->link = new_node;
}


void insert_before(struct node *ptr, int data)
{
	int tmp=0;
	if(ptr == NULL)
		return;
	if(ptr->link == NULL)
	{
		printf("Can't insert data before last node, without start  node\n");
		return;
	}
	insert_after(ptr, data);
	tmp = ptr->data;
	ptr->data = ptr->link->data;
	ptr->link->data = tmp;
}
