//C program that implement stack (its operations) using Linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *next;
};

struct node *top = NULL;

struct node *push(struct node *, int);
struct node *display(struct node *);
struct node *pop(struct node *);
int peek(struct node *);

void main() 
{
	int val, option;
	do
	{
 		printf("\n *****MAIN MENU*****");
 		printf("\n 1. PUSH");
 		printf("\n 2. POP");
 		printf("\n 3. PEEK");
 		printf("\n 4. DISPLAY");
 		printf("\n 5. EXIT");
 		printf("\n Enter your option: ");
 		scanf("%d", &option);
 		switch(option)
 		{
 			case 1:
 				printf("\n Enter the number to be pushed on stack: ");
 				scanf("%d", &val);
 				top = push(top, val);
 				break;
 			case 2:
 				top = pop(top);
 				break;
 			case 3:
 				val = peek(top);
 				if (val != -1)
 					printf("\n The value at the top of stack is: %d", val);
 				else
 					printf("\n STACK IS EMPTY");
 				break;
 			case 4:
 				top = display(top);
 				break;
		}
	}while(option != 5);
}


struct node *push(struct node *top, int val)
{
	struct node* ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=val;
	if(top==NULL)
	{
		ptr->next=NULL;
		top=ptr;
	}
	else
	{
		ptr->next=top;
		top=ptr;
	}
	return top;
}


struct node *pop(struct node *top)
{
	struct node* ptr = top;
	if(top==NULL)
		printf("\n UNDERFLOW");
	else
	{
		top=top->next;
		printf("\n the value deleted is %d",ptr->data);
		free(ptr);
	}
	return top;
}


int peek(struct node *top)
{
	if(top == NULL)
		return -1;
	else
		return top->data;
}


struct node *display(struct node *top)
{
	struct node* ptr=top;
	if(top==NULL)
		printf("\nUNDERFLOW");
	else
	{
		while(ptr!=NULL)
		{
			printf("\n %d",ptr->data);
			ptr=ptr->next;
		}
	}
	return top;
}
