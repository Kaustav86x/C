#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct record 
{
	int value;
	struct record *next;	
}NODE;
NODE *front = NULL, *rear = NULL;
void store(int);
void retrieve();
void display();
int main() 
{
	int val, options;
	while(1) 
	{
		printf("\nPress 1 to store data : ");
		printf("\nPress 2 to retrieve data : ");
		printf("\nPress 3 to display : ");
		printf("\nPress 0 to exit : ");
		scanf("%d", &options);
		switch(options) 
		{
			case 1: printf("\nEnter value to store : ");
			        scanf("%d", &val);
			        store(val);
			        break;
			case 2 : retrieve();
			         break;
			case 3 : display();
			         break;
			case 0 : exit(0);
			         break;
			default: printf("\nPlease enter a valid choice !!!!\n");         	
		}
	}
	return 0;
}

void store(int x)
{
	NODE *temp;
	temp = (NODE*)malloc(sizeof(NODE));
	if(temp == NULL) 
	{
		printf("\nQueue overflow\n");
		return;
	}
	temp->value = x;
	temp->next = NULL;
	if(rear == NULL) 
	{
		front = temp;
		rear = temp;
	}
	else 
	{
		rear->next = temp;
		rear = rear->next;
	}
}

void retrieve() 
{
	NODE *temp;
	int val;
	if(front == NULL) 
	{
		printf("\nQueue underflow!!\n");
		return ;
	}	
	val = front->value;
	temp = front;
	if(front == rear) 
	{
		front = NULL;
		rear = NULL;
	}
	else 
	front = front->next;
	free(temp);
	printf("\nThe retrieved data is = %d\n", val);
	return;
}

void display() 
{
	NODE *temp;
	temp = front;
	if(temp == NULL) 
	{
		printf("\nNothing to display, Queue is empty !!!\n");
		return;
	} 
	    printf("\nThe data in the Queue are : \n");
		while(1)
		 {
		 	printf("%d\n", temp->value);
		 	temp = temp->next;
		 	if (temp == NULL)
		 	break;
		 	
		 }
}
