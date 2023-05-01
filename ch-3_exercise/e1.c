//To count no. of occurrences of an element in a single linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
int count_ele(struct node *start, int data);

int main()
{
	int input=0, data=0, count=0;
	struct node *start= NULL;
	while(1)
	{
		printf("Enter input\n");
		printf("1. Create linked list\n");
		printf("2. Display\n");
		printf("3. Count no. of occurrences\n");
		printf("4. Quit\n");
		scanf("%d", &input);

		switch(input)
		{
			case 1:
				start = create(start);
				break;
			case 2:
				display(start);
				break;
			case 3:
				printf("Enter element, which you want to count\n");
				scanf("%d", &data);
				count = count_ele(start, data);
				printf("%d element occurred %d times\n", data, count);
				break;
			case 4:
				exit(1);
			default :
				printf("Invalid input\n");
		}
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


int count_ele(struct node *start, int data)
{
	int count=0;
	struct node *cur=NULL;
	cur = start;
	while(cur != NULL)
	{
		if(cur->data == data)
			++count;
		cur = cur->link;
	}
	return count;
}

