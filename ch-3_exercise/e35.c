/*
Add two numbers represented by double linked list. In which info part contain 4 digits of number in reverse orlder.
Ex. number 342398 should be represented by 2398->34
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int digit;
	struct node *prev;
	struct node *next;
};

struct node *get_list(unsigned long int num);
void display(struct node *start);
unsigned long int add_num(struct node *start_1, struct node *start_2);

int main()
{
	unsigned long int num_1=0, num_2=0, sum=0;
	struct node *start_1=NULL, *start_2=NULL;
	printf("Enter 1st number : ");
	scanf("%ld", &num_1);
	printf("Enter 2nd number :");
	scanf("%ld", &num_2);

	start_1 = get_list(num_1);
	printf("1st number linked list : ");
	display(start_1);
	start_2 = get_list(num_2);
	printf("2nd number linked list : ");
	display(start_2);
	
	sum = add_num(start_1, start_2);
	printf("%ld + %ld = %ld\n", num_1, num_2, sum);
	
	return 0;
}


struct node *get_list(unsigned long int num)
{
	struct node *start=NULL, *new_node=NULL, *prev_node=NULL;
	do
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->digit = num%10000;
		num /= 10000;
		new_node->next = NULL;
		new_node->prev = prev_node;
		if(start == NULL)
			start = new_node;
		else
			prev_node->next = new_node;
		prev_node = new_node;
	}while(num > 0);
	return start;
}


void display(struct node *start)
{
	while(start != NULL)
	{
		printf("%d  ", start->digit);
		start = start->next;
	}
	printf("\n");
}


unsigned long int add_num(struct node *start_1, struct node *start_2)
{
	unsigned long int sum=0, sum_digit=0, carry=0, mul_factor=1;
	struct node *cur_1=start_1, *cur_2=start_2;
	while(cur_1 != NULL  ||  cur_2 != NULL)
	{
		if(cur_1 == NULL  &&  cur_2 != NULL)
			sum_digit = carry + cur_2->digit;
		else if(cur_2 == NULL  &&  cur_1 != NULL)
			sum_digit = carry + cur_1->digit;
		else
			sum_digit = carry + cur_1->digit + cur_2->digit;
		carry = sum_digit / 10000;
		sum += (sum_digit % 10000) * mul_factor;
		
		mul_factor *= 10000;
		if(cur_1 != NULL)
			cur_1 = cur_1->next;
		if(cur_2 != NULL)
			cur_2 = cur_2->next;
		//printf("---> %d \n", sum);
	}
	if(carry != 0)
	{
		sum += carry * mul_factor;
	}
	return sum;
}
