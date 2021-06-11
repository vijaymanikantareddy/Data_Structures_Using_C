/*  C program that implement Queue (its operations) using linked lists */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
	int data;
	struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

struct node *insert(struct node *,int);
struct node *delete_element(struct node *);
struct node *display(struct node *);
void peek(struct node*);
bool isEmpty(struct node*);


void main()
{
	int val, option;
	bool x;
	do
	{
 		printf("\n\n *****MAIN MENU*****");
 		printf("\n 1. Insert an element ");
 		printf("\n 2. Delete an element");
 		printf("\n 3. Peek value");
 		printf("\n 4. Check queue is empty");
 		printf("\n 5. Display the queue");
 		printf("\n 6. EXIT");
 		printf("\n Enter your option : ");
 		scanf("%d", &option);
		switch(option)
 		{
 			case 1:
 				printf("\n Enter the number to insert in the queue:");
 				scanf("%d", &val);
 				front = insert(front,val);
 				break;
 			case 2:
 				front = delete_element(front);
 				break;
 			case 3:
 				peek(front);
 				break;
 			case 4:
				x=isEmpty(front);
				if(x==true)
					printf("\n the queue is empty");
				else
					printf("\n the queue is not empty");
				break;
			case 5:
				front = display(front);
 				break;
 		}
	}while(option > 0 && option < 6);
}

// this function is used to insert an element in to a queue
struct node *insert(struct node * front,int val)
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr -> data = val;
	if( front == NULL)
	{
 		front = ptr;
 		rear = ptr;
 		front -> next = rear -> next = NULL;
	}
	else
	{
 		rear -> next = ptr;
 		rear = ptr;
 		rear -> next = NULL;
	}
	return front;
}

//this function is used to delete an element an element from a queue.
struct node *delete_element(struct node *front)
{
	struct node *ptr;
	ptr = front;
	if(front == NULL)
 		printf("\n UNDERFLOW");
	else
	{
 		front = front -> next;
 		printf("\n The value being deleted is : %d", ptr -> data);
 		free(ptr);
	}
	return front;
}

//this function displays front value.
void peek(struct node *front)
{
	if(front==NULL)
 		printf("\n QUEUE IS EMPTY");
	else
 		printf("\nPeek = %d",front->data);
}

//this function checks the queue is empty or not.
bool isEmpty(struct node * front)
{
	if(front==NULL)
		return true;
	else 
		return false;	
}

// this function is used to display the elements of queue
struct node *display(struct node *front)
{
	struct node *ptr;
	ptr = front;
	if(ptr == NULL)
 		printf("\n QUEUE IS EMPTY");
	else
	{
 		printf("\n");
 		while(ptr!=rear)
 		{
 			printf("%d\t", ptr -> data);
 			ptr = ptr -> next;
 		}
 		printf("%d\t", ptr -> data);
	}
	return front;
}
