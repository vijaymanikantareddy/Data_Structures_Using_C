/* Circular LinkedList - Insertion - Beginning , Ending, Specific Position*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
 int data;
 struct node *next;
};
struct node *start = NULL;
struct node *create_cll(struct node *);
void *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_sp(struct node *);
void main()
{
 	int option;
 	do
 	{
		printf("\n\n *****MAIN MENU *****");
		printf("\n 1: Create a list");
		printf("\n 2: Display the list");
		printf("\n 3: Add a node at the beginning");
		printf("\n 4: Add a node at the end");	
		printf("\n 5: Add a node at a specific position");
		printf("\n 6: EXIT");
		printf("\n\n Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
 			case 1: 
			 		start = create_cll(start);
 					printf("\n Circular Linked List is Created.");
 					break;
 			case 2: 
			 		display(start);
 					break;
 			case 3: 
			 		start = insert_beg(start);
 					break;
 			case 4: 
			 		start = insert_end(start);
 					break;
 			case 5: 
			 		start = insert_sp(start);
 					break;		
		}
 	}while(option !=6);
}

struct node *create_cll(struct node *start)
{
	struct node *newnode, *ptr;
 	int num,n,i;
 	printf("enter the number of nodes to store in the linked list: ");
 	scanf("%d",&n);
 	for(i=1;i<=n;i++)
 	{
 		printf("enter the data in the %d node: ",i);
 		scanf("%d",&num);
 		newnode = (struct node*)malloc(sizeof(struct node));
 		newnode -> data = num;
 		if(start == NULL)
 		{
 			start = newnode;
 			newnode -> next = newnode;
  		}
 		else
 		{ 
		 	ptr = start;
 			while(ptr -> next != start)
 				ptr = ptr -> next;
 			newnode -> next = start;
 			ptr -> next = newnode;
 		}
	}
	return start;
}

void *display(struct node *start)
{
	struct node*ptr;
	ptr=start;
	if(start==NULL)
	{
		printf("List does not exist!");
	}
	else
	{
		while(ptr -> next != start)
		{
 			printf("\t %d", ptr -> data);
 			ptr = ptr -> next;
		}
		printf("\t %d", ptr -> data);
	}
}

struct node *insert_beg(struct node *start)
{
	struct node *newnode, *ptr;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	if(start==NULL)
	{
		start=newnode;
		newnode->next=start;
	}
	else
	{
		struct node* ptr=start;
		while(ptr->next != start)
			ptr=ptr->next;
		ptr->next=newnode;
		newnode->next=start;
		start=newnode;
	}
	return start;
}

struct node *insert_end(struct node *start)
{
	struct node *newnode;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	if(start==NULL)
	{
		start=newnode;
		newnode->next=start;
	}
	else
	{
		struct node* ptr=start;
		while(ptr->next != start)
			ptr=ptr->next;
		ptr->next=newnode;
		newnode->next=start;	
	}
	return start;
}

struct node* insert_sp(struct node *start)
{
	int num, pos, i;
	struct node* ptr=start, *newnode, *temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter number & position: ");
	scanf("%d %d",&num,&pos);
	newnode->data=num;
	for(i=1 ; i<pos ; i++)
		ptr=ptr->next;
	temp=ptr;
	newnode->next=ptr->next;
	temp->next=newnode;		
	return start;
}
