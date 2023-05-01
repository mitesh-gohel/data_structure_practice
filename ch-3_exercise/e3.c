//To check whether two single linked lists are identical
//Two lists are idetical if they have same number of elements and the corresponding elements in both lists are same.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
int is_identical(struct node *start_1, struct node *start_2);

int main()
{
	int ret=0;
	struct node *start_1= NULL, *start_2=NULL;
	
	printf("For 1st list :\n");
	start_1 = create(start_1);
	printf("For 2nd list :\n");
	start_2 = create(start_2);
	printf("1st list : ");
	display(start_1);
	printf("2nd list : ");
	display(start_2);
	ret = is_identical(start_1, start_2);
	if(ret == 1)
		printf("List is identical\n");
	else
		printf("List is not identical\n");
	
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


int is_identical(struct node *start_1, struct node *start_2)
{
	struct node *cur_1=start_1, *cur_2=start_2;
	while(cur_1 != NULL  &&  cur_2 != NULL)
	{
		if(cur_1->data != cur_2->data)
			return 0;
		cur_1 = cur_1->link;
		cur_2 = cur_2->link;
	}
	if(cur_1 == NULL  && cur_2 == NULL)	//means both list cur pointer is reached to end in above while loop
		return 1;
	else
		return 0;
}

