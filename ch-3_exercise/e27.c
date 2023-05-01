/*
Detecting and Removing a cycle/loop in a single linked list 
--> Find list containn NULL or cycle/loop
--> Find length of cycle
--> Find length of list
--> Find out node which cause cycle/loop
--> Remove loop
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct addr_list
{
	struct node *addr;
	struct addr_list *link;
};

struct node *create(struct node *start);
struct addr_list *insert(struct addr_list *start, struct node *addr);
struct node *find_loop_node(struct node *start);
void display(struct node *start);
void create_loop(struct node *start, int loop_val);
int is_loop_list(struct node *start);
int find_list_len(struct node *start);
int find_loop_len(struct node *loop_node);
void destroy_addr_list(struct addr_list *start);
void destroy_node(struct node *start);
void remove_loop(struct node *loop_node);

int main()
{
	struct node *start=NULL, *loop_node=NULL;
	char choice;
	int loop_val=0;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list : ");
	display(start);
	
	printf("Do you want to create cycle/loop in linked list ?   Y/N ?\n");
	scanf(" %c", &choice);
	if(choice == 'Y')
	{
		printf("Enter value for which you want to create loop : \n");
		scanf("%d", &loop_val);
		create_loop(start, loop_val);
	}
	loop_node = find_loop_node(start);
	if(loop_node != NULL)
	{
		printf("Linked list contains loop/cycle\n");
		printf("Node of data %d cause loop/cycle", loop_node->data);
		printf("Length of loop = %d\n", find_loop_len(loop_node));
		remove_loop(loop_node);
	}
	else
	{
		printf("Linked list is terminated by NULL\n");
	}
	printf("Length of list = %d\n", find_list_len(start));
	destroy_node(start);
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


struct addr_list *insert(struct addr_list *start, struct node *addr)
{
	struct addr_list *new_node=NULL;
	new_node = (struct addr_list *)malloc(sizeof(struct addr_list));
	new_node->addr = addr;
	if(start == NULL)
	{
		new_node->link = NULL;
		return new_node;
	}
	new_node->link = start;
	start = new_node;
	return start;
}


int is_present(struct addr_list *start, struct node *addr)
{
	while(start != NULL)
	{
		if(start->addr == addr)
			return 1;
		start = start->link;
	}
	return 0;
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


void create_loop(struct node *start, int loop_val)
{
	struct node *cur=NULL, *last_node=NULL;
	last_node = start;
	while(last_node->link != NULL)
		last_node = last_node->link;
	cur = start;
	while(cur != NULL  &&  cur->data != loop_val)
		cur = cur->link;
	if(cur != NULL)
		last_node->link = cur;
	else
		printf("Loop generation failed\n");
	
}


struct node *find_loop_node(struct node *start)
{
	struct node *cur=NULL;
	struct addr_list *addr_start=NULL;
	cur = start;
	while(cur != NULL)
	{
		addr_start = insert(addr_start, cur);
		if(is_present(addr_start, cur->link))
		{
			destroy_addr_list(addr_start);
			addr_start = NULL;
			return cur->link;;
		}
		cur = cur->link;
	}
	destroy_addr_list(addr_start);
	addr_start = NULL;
	return NULL;
}


int find_list_len(struct node *start)
{
	int len=0;
	while(start != NULL)
	{
		++len;
		start = start->link;
	}
	return len;
}


void destroy_addr_list(struct addr_list *start)
{
	struct addr_list *del=NULL;
	while(start != NULL)
	{
		del = start;
		start = start->link;
		free(del);
		del = NULL;
	}
}


void destroy_node(struct node *start)
{
	struct node *del=NULL;
	while(start != NULL)
	{
		del = start;
		start = start->link;
		free(del);
		del = NULL;
	}
}


int find_loop_len(struct node *loop_node)
{
	if(loop_node == NULL)
		return 0;
	struct node *cur=NULL;
	int len=0;
	cur = loop_node;
	++len;
	while(cur->link != loop_node)
	{
		++len;
		cur = cur->link;
	}
	return len;
}


void remove_loop(struct node *loop_node)
{
	struct node *cur=NULL;
	cur = loop_node;
	while(cur->link != loop_node)
		cur = cur->link;
	cur->link = NULL;
}
