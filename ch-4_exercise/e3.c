//Implement a stack in array such that the stack starts from the last position of array.

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void push(int data);
int pop();
void display();
int is_empty();
int is_full();

int top = -1;
int arr[SIZE];

int main()
{
	int choice=0, data=0;
	while(1)
	{
		printf("Select choice : \n");
		printf("1. Insert data \n");
		printf("2. Delete data \n");
		printf("3. Display stack \n");
		printf("4. Exit \n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 :
				printf("Enter data : ");
				scanf("%d", &data);
				push(data);
				break;
			case 2 :
				data = pop();
				printf("Deleted data : %d \n", data);
				break;
			case 3 :
				display();
				break;
			case 4 :
				exit(0);
			default :
				printf("Invalid choice \n");
		}
	}
	return 0;
}


int is_empty()
{
	if(top == -1)
		return 1;
	return 0;
}


int is_full()
{
	if(top == 0)
		return 1;
	return 0;
}


void push(int data)
{
	if(is_full())
	{
		printf("Overflow \n");
		exit(1);
	}
	if(top == -1)
		top = SIZE-1;
	else
		top -= 1;
	arr[top] = data;
}


int pop()
{
	int data;
	if(is_empty())
	{
		printf("Underflow \n");
		exit(1);
	}
	data = arr[top];
	if(top == SIZE-1)
		top = -1;
	else
		top += 1;
	return data;
}


void display()
{
	int i=0;
	if(is_empty())
	{
		printf("Stack is empty\n");
		return;
	}
	for(i=top; i<=SIZE-1; ++i)
		printf("%d \n", arr[i]);
}

