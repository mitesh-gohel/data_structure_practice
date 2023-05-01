//To create a reverse list, without changing original list

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
struct node *get_copy(struct node *start);
struct node *get_reverse(struct node *start);

int main()
{
	struct node *start_1=NULL, *start_2=NULL;
	
	printf("For linked list :\n");
	start_1 = create(start_1);
	printf("Provided list 	: ");
	display(start_1);
	start_2 = get_reverse(start_1);
	printf("Reverse list 	: ");
	display(start_2);
	
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


struct node *get_copy(struct node *start)
{
	struct node *cur=NULL, *new_start=NULL, *new_node=NULL, *pre=NULL;

	cur = start;
	while(cur != NULL)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->data = cur->data;
		new_node->link = NULL;

		if (new_start == NULL) //if 1st node of list
		{
			new_start = new_node;
			pre = new_node;
		}
		else
		{
			pre->link = new_node;
			pre = new_node;
		}
			
		cur = cur->link;
	}
	return new_start;
}


struct node *get_reverse(struct node *start)
{
	struct node *r_start=NULL, *cur=NULL, *pre=NULL, *next=NULL; //start node of revered list is r_start
	r_start = get_copy(start);

	if(r_start == NULL  ||  r_start->link == NULL) //if list is empty OR no. of node is 1 then reverse will be same
		return r_start;

	cur = r_start; 	// start from 1st node
	pre = NULL;	//previous of 1 will be nothing, so NULL
	do
	{
		next = cur->link;	//next node, where we want to go 
		cur->link = pre;	//chnage link of current node, to do reverse
		pre = cur;		//store pre for next node iteration
		cur = next;		//go to next node
	}while(cur != NULL);
	r_start = pre;			//change start node of reversed list
	
	return r_start;
}
