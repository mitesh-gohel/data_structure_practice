//Implement 2 stack in single array of size N

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void pushA();
void pushB();
int popA();
int popB();
void displayA();
void displayB();
int isEmptyA();
int isEmptyB();
int isFUll();

int arr[SIZE];
int top_A=-1, top_B=-1;

int main()
{
	int choice=0, data=0;
	while(1)
	{
		printf("Select choice : \n");
		printf("1. Insert data in stack A \n");
		printf("2. Insert data in stack B \n");
		printf("3. Delete data from stack A \n");
		printf("4. Delete data from stack B \n");
		printf("5. Display stack A \n");
		printf("6. Display stack B \n");
		printf("7. Exit \n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 :
				printf("Enter data : ");
				scanf("%d", &data);
				pushA(data);
				break;
			case 2 :
				printf("Enter data : ");
				scanf("%d", &data);
				pushB(data);
				break;
			case 3 :
				data = popA();
				printf("Deleted data : %d \n", data);
				break;
			case 4 :
				data = popB();
				printf("Deleted data : %d\n", data);
				break;
			case 5 :
				displayA();
				break;
			case 6 :
				displayB();
				break;
			case 7 :
				exit(0);
			default :
				printf("Invalid choice \n");
		}
	}
	return 0;
}


int isEmptyA()
{
	if(top_A == -1)
		return 1;
	return 0;
}


int isEmptyB()
{
	if(top_B == -1)
		return 1;
	return 0;
}


int isFull()
{
	if((top_A + 1 == top_B)  ||  (top_A == SIZE-1  &&  top_B == -1))
		return 1;
	return 0;
}


void pushA(int data)
{
	if(isFull())
	{
		printf("Overflow\n");
		exit(1);
	}
	arr[++top_A] = data;
}


void pushB(int data)
{
	if(isFull())
	{
		printf("Overflow\n");
		exit(1);
	}
	if(top_B == -1)
		top_B = SIZE-1;
	else
		top_B -= 1;
	arr[top_B] = data;
}


int popA()
{
	int data=0;
	if(isEmptyA())
	{
		printf("Underflow\n");
		exit(1);
	}
	data = arr[top_A];
	top_A -= 1;
	return data;
}


int popB()
{
	int data=0;
	if(isEmptyB())
	{
		printf("Underflow\n");
		exit(1);
	}
	data = arr[top_B];
	if(top_B == SIZE-1)
		top_B = -1;
	else
		top_B += 1;
	return data;
}


void displayA()
{
	int i=0;
	if(isEmptyA())
	{
		printf("Stack A is empty\n");
		return;
	}
	printf("Stack A :\n");
	for(i=top_A; i >= 0; --i)
			printf("%d\n", arr[i]);
}


void displayB()
{
	int i=0;
	if(isEmptyB())
	{
		printf("Stack B is empty\n");
		return;
	}
	printf("Stack B :\n");
	for(i=top_B; i<SIZE; ++i)
		printf("%d\n", arr[i]);
}
