//Implement a stack in an array A, using A[0] as the top

#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

int is_full();
int is_empty();
void push(int data);
int pop(void);
void print_stack();

int arr[SIZE];
int top=-1;


int main()
{
	int choice=0, data=0;
	while(1)
	{
		printf("Enter choice : \n");
		printf("1. Push data inno stack\n");
		printf("2. Pop data from stack\n");
		printf("3. Print stack\n");
		printf("4 exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 :
				printf("Enter data : \n");
				scanf("%d", &data);
				push(data);
				break;
			case 2 :
				data = pop();
				printf("Data = %d\n", data);
				break;
			case 3 :
				print_stack();
				break;
			case 4 :
				exit(0);
			default :
				printf("Invalid input\n");
				break;
		}
	}
	return 0;
}


int is_full()
{
	if(top == SIZE-1)
		return 1;
	else
		return 0;
}


void push(int data)
{
	if(is_full())
	{
		printf("Overflow \n");
		exit(1);
	}
	arr[++top] = data;
}


int is_empty()
{
	if(top == -1)
		return 1;
	else 
		return 0;
}


int pop()
{
	if(is_empty())
	{
		printf("Underflow \n");
		exit(1);
	}
	return arr[top--];
}


void print_stack()
{
	int i=0;
	printf("Stack : \n");
	for(i=top; i>=0; --i)
		printf("%d \n", *(arr + i));
}

