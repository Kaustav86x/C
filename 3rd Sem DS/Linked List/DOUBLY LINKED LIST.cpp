#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node *next;
	struct node *prev;
}NODE;
NODE *start = NULL;
void create(int);
void display();
void insert_specific_pos(int, int);
void del_node_val(int);
void del_node_pos(int);
void reverse();
void search(int);
int main()
{
	int m, n, options, l, v, p, val, d, po;
	while(1)
	{
		printf("\nEnter\n1 to create the list:\n2 to display:\n3 to insert a node at a specific position:\n4 to delete a value from the list :\n5 to delete a position from a list:\n6 to search for an element:\n7 to reverse\n8 to exit:\n");
		scanf("%d", &options);
		switch(options)
		{
			case 1: printf("\nEnter the initial population : ");
			        scanf("%d", &n);
			        for(int i=0; i<n; i++)
			       {
				    printf("\nEnter the %d th value : ",i);
				    scanf("%d", &m);
				    create(m);
			       }
			       break;
			case 2:printf("\nTHE LINKED LIST IS DISPLAYED BELOW : \n");
			       display();
				   break;    
			case 3:printf("\nEnter the value to be inserted and the position : ");
			       scanf("%d %d", &val, &p);
				   insert_specific_pos(val ,p);
				   break;
			case 4:printf("\nEnter the value to be deleted : ");
			       scanf("%d", &d);
				   del_node_val(d);
				   break;
			case 5:printf("\nEnter the position to be deleted from the list: ");
			       scanf("%d", &po);
			       del_node_pos(po);
				   break;   
			case 6:printf("\nEnter the value to be searched in the list : ");
			       scanf("%d", &l);
				   search(l);
				   break;
			case 7:reverse();
				   break;	   
		   case 8: exit(0);	     	    
		}
	}
	return 0;
}

void create(int num)
{
	NODE *temp, *q;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = num;
	temp->next = NULL;
	if(start == NULL)
	{
		temp->prev = NULL;
		start = temp;
	}
	else
	{
		q = start;
		while(q->next!=NULL)
		{
			q = q->next;
		}
		q->next = temp;
		temp->prev = q;
	}

}

void display()
{
	NODE *q;
	int count = 0;
	q = start;
	if(start == NULL)
	printf("\nOops !!! The list is empty\n");
	else{
		
	while(q->next!=NULL)
	{
		printf("\nThe %dth value : %d\n", count, q->data);
		q = q->next;
		count++;
	}
	printf("\nThe %dth value : %d\n", count, q->data);		
	}

}

void insert_specific_pos(int num, int pos)
{
	NODE *q, *temp;
	q = start;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = num;
	if (pos == 0)
	{
	temp->data = num;
	temp->next = start;
	temp->prev = NULL;
	start = temp;
	return;
	}
	while((pos > 1)&&(q!=NULL))
	{
		q = q->next;
		pos--;
	}
	if(q == NULL)
	    printf("\nPLEASE ENTER A VALID POSITION !!!\n");
	else{
		
		temp->next = q->next;   // in case of insertion at last q->next == NULL.
	    temp->prev = q;
	    q->next = temp;   
	    if(temp->next!=NULL)
	    temp->next->prev = temp;
	}    
		

}

void del_node_val (int val)
{
	NODE *q, *temp;
	if (start == NULL)
	{
		printf("\nSorry! The list is empty. Enter data first\n");
	}
	else
	{
		if (start->data == val)
	{
		temp = start;
		start = start->next;
		if(start!=NULL)
		start->prev = NULL;
		free(temp);
		return ;
	}
	q = start;
	while(q->next->next != NULL)
	{
		if (q->next->data == val)
		{
			temp = q->next;
			q->next = temp->next;
			temp->next->prev = temp->prev;
			free(temp);
			return ;
		}
		q = q->next;
	}
	if (q->next->data == val) 
	{
		temp=q->next;
		q->next = NULL;
		free(temp);
		return;
	}
	printf("%d is not present in the list !!!", val);
	}
	
}
void del_node_pos(int pos) 
{
	NODE *q, *temp;
	if (start == NULL) 
	{
		printf("\nSorry ! The list is empty\n");
	}
	else
	{
		if (pos == 0)
	{
		temp = start;
		start = start->next;
		if (start != NULL)
		start->prev = NULL;
		free(temp);
		return ;	
	}
	q = start;
	while (pos>1 && q!= NULL) 
	{
		q = q->next;
		pos--;
	}
	if (q == NULL)
	printf("\nPlease enter a valid position !!!\n");
	else 
	{
		temp = q->next;
		if (temp->next == NULL)
		{
			q->next = NULL;
			free(temp);
			return;
		}
		q->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
		return;
	}
	}	
	
}
void search(int val)
{
	NODE *q = start;
	int count = 0, flag =0 ;
	if(start == NULL)
	printf("\nThe list is empty !!!\n");
	else
	{
		while(q!=NULL)
		{
			if(q->data == val)
			{
				printf("\nElement %d found at %d th position\n",q->data,count);
				flag = 1;
				break;
				
			}
			q = q->next;
			count++;
		}
		if (flag == 0)
		printf("\nThe value %d is not present in the list !!\n", val);

	}	

}
void reverse()
{
	NODE *p1, *p2;
	p1 = start;
	p2 = start->next;
	p1->next = NULL;
	p1->prev = p2;
	while (p2!=NULL) 
	{
		p2->prev = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p2->prev;
	}
	start = p1;
}

