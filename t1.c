//Circular linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create_list(struct node *last);
void display(struct node *last);
struct node *addtoempty(struct node *last, int data);
struct node *addatbeg(struct node *last, int data);
struct node *addatend(struct node *last, int data);
struct node *addafter(struct node *last, int data, int item);
struct node *del(struct node *last, int data);

int main()
{
	int input=0, data=0, item=0;
	struct node *last = NULL;

	while(1)
	{
		printf("Enter input\n");
		printf("1. Create list\n");
		printf("2. Display\n");
		printf("3. Add to empty list\n");
		printf("4. Add at beginning\n");
		printf("5. Add at end\n");
		printf("6. Add after\n");
		printf("7. Delete\n");
		printf("8. Quit\n");
		scanf("%d", &input);

		switch(input)
		{
			case 1:
				last = create_list(last);
				break;
			case 2:
				display(last);
				break;
			case 3:
				printf("Enter data :\n");
				scanf("%d", &data);
				last = addtoempty(last, data);
				break;
			case 4:
				printf("Enter data :\n");
				scanf("%d", &data);
				last = addatbeg(last, data);
				break;
			case 5:
				printf("Enter data :\n");
				scanf("%d", &data);
				last = addatend(last, data);
				break;
			case 6 :
				printf("Enter data to be inserted :\n");
				scanf("%d", &data);
				printf("Enter element after which data to be insert :\n");
				scanf("%d", &item);
				last = addafter(last, data, item);
				break;
			case 7:
				printf("Enter data to be deleted\n");
				scanf("%d", &data);
				last = del(last, data);
				break;
			case 8:
				exit(0);
			default :
				printf("\nEnter valid input\n\n");
		}
	}
	return 0;
}


//my logic
struct node *create_list(struct node *last)
{
	int num_of_node=0, i=0, data=0;
	struct node *new_node=NULL;
	last = NULL;

	printf("Enter no. of node, you want to create\n");
	scanf("%d", &num_of_node);
	for(i=0; i < num_of_node; ++i)
	{
		printf("Enter data of node no.%d : \n", i+1);
		scanf("%d", &data);
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->data = data;
		if (last==NULL)
		{
			new_node->link = new_node;
		}
		else
		{
			new_node->link = last->link;
			last->link = new_node;
		}
		last = new_node;
	}
	return last;
}


void display(struct node *last)
{
	struct node *cur;
	if (last == NULL)
	{
		printf("No data in list\n");
		return;
	}
	cur = last;
	do
	{
		cur = cur->link;
		printf("%d  ", cur->data);
	}while(cur != last);
	printf("\n");
}


struct node *addtoempty(struct node *last, int data)
{
	struct node *new_node=NULL;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->link = new_node;
	last = new_node;
	return last;
}


struct node *addatbeg(struct node *last, int data)
{
	struct node *new_node=NULL;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	if(last == NULL)
	{
		new_node->link = new_node;
		last = new_node;
	}
	else
	{
		new_node->link = last->link;
		last->link = new_node;
	}
	return last;
}


struct node *addatend(struct node *last, int data)
{
	struct node *new_node=NULL;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	if(last == NULL)
		new_node->link = new_node;
	else
	{
		new_node->link = last->link;
		last->link = new_node;
	}
	last = new_node;
}


struct node *addafter(struct node *last, int data, int item)
{
	struct node *cur=NULL, *new_node=NULL;
	if(last == NULL)
	{
		printf("List is empty\n");
		return last;
	}
	
	cur = last;
	do
	{
		cur = cur->link;
		if(cur->data == item)
		{
			new_node = (struct node *)malloc(sizeof(struct node));
			new_node->data = data;
			new_node->link = cur->link;
			cur->link = new_node;
			if(cur == last)
				last = new_node;
			break;
		}
	}while(cur != last);
	return last;
}


//my logic
struct node *del(struct node *last, int data)
{
	struct node *cur=NULL, *del_node=NULL;
	if(last == NULL)
	{
		printf("List is empty\n");
		return last;
	}
	
	cur = last;
	do
	{
		cur = cur->link;
		if(cur->link->data == data)
		{
			del_node = cur->link;
			cur->link = cur->link->link;
			if (del_node == last)
			{
				last = cur;
				if (last == last->link)	//if only 1 ele in list
					last = NULL;
			}
			free(del_node);
			del_node = NULL;
			break;
		}
	}while(cur != last);
	return last;
}
