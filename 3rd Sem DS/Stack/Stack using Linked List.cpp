#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct record 
{
	int value;
	struct record *next;
} NODE;
NODE *top = NULL;
void push(int);
void pop();
void display();
int main() 
{
	int val, options;
	while(1) 
	{
		printf("\nPress 1 to push : ");
		printf("\nPress 2 to pop : ");
		printf("\nPress 3 to display : ");
		printf("\nPress 0 to exit : ");
		scanf("%d", &options);
		switch(options) 
		{
			case 1 : printf("\nEnter value to insert in the stack : ");
			         scanf("%d", &val);
			         push(val);
			         break;
			case 2 : pop();
			         break;
			case 3 : display();
			         break;
			case 0 : exit(0);
			         break;
			default: printf("\nEnter a valid choice !!!!! \n");		 		 		          
		}
	}
	return 0;
}

void push(int x) 
{
	NODE *temp;
	temp = (NODE*)malloc(sizeof(NODE));
	if (temp == NULL)
	{
		printf("\nStack overflow !!!");
		return;
	}
	temp->value = x;
	temp->next = top;
	top = temp;
}
void pop() 
{
	NODE *temp;
	int val;
	if (top == NULL) 
	{
		printf("\nStack Underflow !!!");
		return;
	}
	val = top->value;
	temp = top;
	top = top->next;
	free(temp);
	printf("\nPopped value = %d\n", val);
	return;
}

void display() 
{
	NODE *temp;
	int i = 0;
	temp = top;
	if(temp == NULL)
	{
		printf("\nThe stack is empty !!!\n");
		return;
	}
	printf("\nThe elements in the stack are : \n");
	while(1)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
		i++;
		if(temp == NULL) 
		break;
	}
}
