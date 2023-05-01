//To find the middle node in a single linked list 

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
struct node *find_middle(struct node *start);

int main()
{
	struct node *start=NULL, *middle=NULL;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list			: ");
	display(start);
	middle = find_middle(start);
	if(middle != NULL)
		printf("Middle node element = %d\n", middle->data);
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


struct node *find_middle(struct node *start)
{
	struct node *cur_1=NULL, *cur_2=NULL;
	if(start == NULL)
		return NULL;
	cur_1 = start;
	cur_2 = start;
	while(cur_2->link != NULL  &&  cur_2->link->link != NULL)
	{
		cur_1 = cur_1->link;
		cur_2 = cur_2->link->link;
	}
	return cur_1;
}
