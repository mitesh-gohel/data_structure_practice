//To check that linked list is palindrome or not

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *start);
void display(struct node *start);
int is_palindrome(struct node *start);

int main()
{
	struct node *start= NULL;
	printf("For linked list,\n");
	start = create(start);
	printf("Linked list 		: ");
	display(start);
	if(is_palindrome(start))
		printf("Linked list is plalindrome\n");
	else
		printf("Linked list is not palindrome\n");
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


int is_palindrome(struct node *start)
{
	int len = 0, i = 0, j = 0, k = 0;
	struct node *cur_1=NULL, *cur_2=NULL;
	if(start == NULL)
	{
		printf("Linked is empty\n");
		return 0;
	}
	cur_1 = start;
	for(; cur_1; ++len, cur_1 = cur_1->link);
	
	cur_1 = start;
	cur_2 = start;
	
	for(j=0; j<len/2 ; j++)
	{
		if(j==0)
			cur_1 = start;
		else
			cur_1 = cur_1->link;

		i = len-1-j;
		cur_2 = start;
		for(k=0; k<i; ++k)
			cur_2 = cur_2->link;

		if(cur_1->data != cur_2->data)
			return 0;
	}
	return 1;
}
