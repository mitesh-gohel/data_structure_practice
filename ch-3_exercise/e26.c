//Get the nth node from the end of a single linked list, without counting elements or revering list

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
struct node *get_node(struct node *start, int n);

int main()
{
	struct node *start=NULL, *n_node=NULL;
	int n=0;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list : ");
	display(start);

	printf("Enter no. of node, which you want : ");
	scanf("%d", &n);
	n_node = get_node(start, n);
	if(n_node !=NULL)
		printf("Data of No.%d = %d\n", n, n_node->data);
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


struct node *get_node(struct node *start, int n)
{
	struct node *p1=NULL, *p2=NULL;
	int i = 0;
	if(n < 1)
	{
		printf("Invalid no. of node\n");
		return NULL;
	}
	p1 = start;
	for(i=0; i<n; ++i)
	{
		if(p1 != NULL)
		{
			p1 = p1->link;
		}
		else
		{
			printf("Only %d nodes available in linked list\n", i);
			return NULL;
		}
	}
	p2 = start;
	while(p1 != NULL)
	{
		p2 = p2->link;
		p1 = p1->link;
	}
	return p2;
}
