//Implement a queue in an array such that if rear reaches the end , all elements are shifted left

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void insert(int data);
int del();
void display();
int is_empty();
int is_Full();

int rear = -1;
int front = -1;
int arr[SIZE];


int main()
{
	int choice=0, data=0;
	while(1)
	{
		printf("Select input : \n");
		printf("1. Insert data \n");
		printf("2. Delete data \n");
		printf("3. Print queue \n");
		printf("4. Exit \n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 :
				printf("Enter data : ");
				scanf("%d", &data);
				insert(data);
				break;
			case 2 :
				data = del();
				printf("Deleted data : %d\n", data);
				break;
			case 3 :
				display();
				break;
			case 4 :
				exit(0);
			default :
				printf("Invalid data\n");
		}
	}
	return 0;
}

int is_empty()
{
	if(front == -1  |  rear == -1)
		return 1;
	else
		return 0;
}


int is_full()
{
	if(rear == SIZE-1)
		return 1;
	else
		return 0;
}


void insert(int data)
{
	int shift_val=0, i=0;
	if(rear == SIZE-1  &&  front >=1)	// Shift all elements to left
	{
		shift_val = front;
		for(i=front; i<=rear; ++i)
			arr[i - shift_val] = arr[i];
		front = 0;
		rear = rear - shift_val;
	}
	if(is_full())
	{
		printf("Overflow\n");
		exit(1);
	}
	arr[++rear] = data;
	if(front == -1)
		front = 0;
}


int del()
{
	int data=0;
	if(is_empty())
	{
		printf("Underflow\n");
		exit(1);
	}
	data = arr[front];
	if(rear-front == 0)  //if only 1 ele present in queue
	{
		front = -1;
		rear = -1;
	}
	else
	{
		front += 1;
	}
	return data;
}


void display()
{
	int i=0;
	if(is_empty())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue : ");
	for(i=front; i<=rear; ++i)
		printf("%d  ", arr[i]);
	printf("\n");
}

