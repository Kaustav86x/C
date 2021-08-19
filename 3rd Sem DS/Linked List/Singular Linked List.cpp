#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data; 
	struct node *next;
}NODE;
void create_list(int);
void display();
void insert_begin(int);
void insert_posi(int, int);
void find_val(int);
void del_pos(int);
void del_last_pos();
void reverse();
NODE *start = NULL;
int main()
{
	int i, choice, n, d, m, s, p, k, val;
	while(1)
	{
		printf("\nPress 1 to create, \n2 to display, \n3 to insert at the beginning, \n4 to insert at any position, \n5 to find a given value in the list, \n6 to delete a value from the list by position, \n7 to print the reverse linked list, \n8 to exit:\t");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: printf("\nEnter the initial population:\t");
			        scanf("%d", &n);
					for(i=0; i<n; i++)
					{
						printf("\nEnter the value of each nodes one by one:\t");
						scanf("%d", &d);
						create_list(d);
					}
					display();
					break;
			case 2: display();
			        break;
		  	case 3: printf("\nEnter the value of the node:\t");
			        scanf("%d", &s);
					insert_begin(s);
					break;
		    case 4: printf("\nEnter the value of the node:\t"); 
			        scanf("%d", &m);
			        printf("\nEnter the position of the node:\t");
			        scanf("%d", &p);
					insert_posi(p, m);
					break;
			case 5: printf("\nEnter the value you want to find in the list:\t");
			        scanf("%d", &k);
			        find_val(k);
			        break;
			case 6: printf("\nEnter the position to be deleted:\t");
			        scanf("%d", &p);
					del_pos(p);
					break;
			case 7: printf("\nThe reverse of the Linked List ");
			        reverse();
			        break;  		     
			case 8: exit(0);
			default : printf("\nEnter a valid choice !!!!\n");
		}
	}
	return 0;
}
void create_list(int num)
{
	NODE *temp, *q;
	q=start;
	temp =(NODE*)malloc(sizeof(struct node));
	temp->data = num;
	temp->next = NULL;
	if(start==NULL)
	{
		start = temp;
	}
	else
	{
		while(q->next!=NULL)
		q = q->next;
		q->next = temp;

	}
}
void insert_begin(int num)
{
	NODE *temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = num;
	temp->next = start;
	start = temp;
}
void insert_posi(int pos, int data)
{
	NODE *curr = start, *temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	if (pos == 0)
	{
		temp->next = curr;
		start = temp;
		return;
	}
	else
	{
	while((pos>1) && (curr!=NULL))
	{
		curr = curr->next;
		pos--;
	}
	if(curr == NULL)
	printf("\nINVALID INDEX !!!");
	else
	{
	temp->next = curr->next;
	curr->next = temp;
	}
	
    }
}
void find_val(int num)
{
	NODE *q;
	q = start;
	int i = 0, flag = 0;
	while(q!=NULL)
	{
		if(q->data == num)
		{
		flag = 1;
		break;
	    }
		i++;
		q = q->next;
	}
	if(flag==1)
	printf("\nThe data is found at %d", i);
	else
	printf("\nThe data is not found");
}
void del_pos(int pos)
{
	NODE  *temp = start, *q;
	if(pos == 0)
	{
		start = start -> next;
		free(temp);
	}
	else
	{
		q = start;
		while (pos > 1 && q != NULL)
		{
			q = q -> next;
			pos --;
	    }
	    
	    	temp = q->next;
	    	if (temp->next == NULL)
	    	{
	    		q->next = NULL;
	    		free(temp);
			}
			else
			{
			q->next = temp->next;
	    	free(temp);
			}
	    	
   }
}
void reverse()
{
	NODE *q = start, *sprev = NULL, *prev = NULL;
	while(q != NULL)
	{
		sprev = prev;
		prev = q;
		q = q->next;
		prev->next = sprev;
	}
	start = prev;
}
void display()
{
	NODE *q;
	q = start;
	int i = 0;
	if(q == NULL)
	printf("\nThe list is empty !!!!\n");
	while(q!=NULL)
	{
		printf("\nThe %dth element is %d\t\n", i, q->data);
		q = q->next;
		i++;
	}
}
