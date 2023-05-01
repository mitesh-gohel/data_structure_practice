//Sorted linkned list

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *insert_s(struct node *start, int data);
void display(struct node *start);

int main()
{
	int input=0, data=0;
	struct node *start = NULL;
	while(1)
	{
		printf("Enter input\n");
		printf("1. Insert\n");
		printf("2. Display\n");
		printf("4. Exit\n");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				printf("Enter data :\n");
				scanf("%d", &data);
				start = insert_s(start, data);
				break;
			case 2:
				display(start);
				break;
			case 4:
				exit(1);
			default :
				printf("\nEnter valid input\n\n");
		}
	}
	return 0;
}


//my logic  <-- repetition od code, Please refer logic from book
struct node *insert_s(struct node *start, int data)
{
	struct node *new_node=NULL, *cur=NULL;
	if(start == NULL)	//if list in empty
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->data = data;
		new_node->link = NULL;
		start = new_node;
		return start;
	}

	cur = start;
	if(data <= cur->data)	//if data is lower value
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->data = data;
		new_node->link = cur;
		start = new_node;
		return start;
	}	
	
	//below log is for : checking by trversing list from node.2 to last node
	cur = start;
	while(cur->link != NULL)
	{
		if(data <= cur->link->data)
		{
			new_node = (struct node *)malloc(sizeof(struct node));
			new_node->data = data;
			new_node->link = cur->link;
			cur->link = new_node;
			return start;
		}
		cur = cur->link;
	}
	//below log is for : if inserted data is larget, so insert at the end
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->link = NULL;
	cur->link = new_node; 	//because of above while loop, cur is pointing to last node
	
	return start;
}


void display(struct node *start)
{
	struct node *cur = NULL;

	cur = start;
	while(cur != NULL)
	{
		printf("%d  ", cur->data);
		cur = cur->link;
	}
	printf("\n");
}
