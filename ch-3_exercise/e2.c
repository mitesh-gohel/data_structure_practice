//To find smallest and largest element in a single linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
struct node *get_min(struct node *start);
struct node *get_max(struct node *start);

int main()
{
	int input=0;
	struct node *start= NULL, *tmp=NULL;
	while(1)
	{
		printf("Enter input\n");
		printf("1. Create linked list\n");
		printf("2. Display\n");
		printf("3. Smallest\n");
		printf("4. largest\n");
		printf("5. Quit\n");
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
				tmp = get_min(start);
				if(tmp == NULL)
					printf("List is empty\n");
				else
					printf("Smallest element = %d\n", tmp->data);
				break;
			case 4:
				tmp = get_max(start);
				if(tmp == NULL)
					printf("List is empty\n");
				else
					printf("Largest element = %d\n", tmp->data);
				break;
			case 5:
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


struct node *get_min(struct node *start)
{
	if(start == NULL)
		return NULL;
	struct node *cur=NULL, *min=NULL;
	
	min = start;
	cur = start->link;
	while(cur != NULL)
	{
		if(cur->data < min->data)
			min = cur;
		cur = cur->link;
	}
	return min;
}


struct node *get_max(struct node *start)
{
	if(start == NULL)
		return NULL;
	struct node *cur=NULL, *max=NULL;

	max = start;
	cur = start->link;
	while(cur != NULL)
	{
		if(cur->data > max->data)
			max = cur;
		cur= cur->link;
	}
	return max;
}
