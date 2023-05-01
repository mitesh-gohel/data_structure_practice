//Split a single linked list into two halves (Means divide linked list into 2 parts)

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
void find_halves(struct node **start, struct node **h_start1, struct node **h_start_2);

int main()
{
	struct node *start=NULL, *h_start_1=NULL, *h_start_2=NULL;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list		: ");
	display(start);
	find_halves(&start, &h_start_1, &h_start_2);
	printf("1st halve linked list 	: ");
	display(h_start_1);
	printf("2nd halve linked list 	: ");
	display(h_start_2);
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


void find_halves(struct node **start, struct node **h_start_1, struct node **h_start_2)
{
	struct node *p1=NULL, *p2=NULL;
	if(*start == NULL)
	{
		*h_start_1 = NULL;
		*h_start_2 = NULL;
		return;
	}
	p1 = *start;
	p2 = *start;
	while(p2->link != NULL  && p2->link->link != NULL)
	{
		p1 = p1->link;
		p2 = p2->link->link;;
	}
	//p1 is middle now
	*h_start_1 = *start;
	*h_start_2 = p1->link;
	p1->link = NULL;
}
