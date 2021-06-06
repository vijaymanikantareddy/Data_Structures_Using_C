/* Double LinkedList - Insertion & Deletion - beginning, ending, after a node */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* prev;
	int data;
	struct node* next;
};
struct node *start=NULL;
struct node* create_dll(struct node*);
void display(struct node*);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);

void main()
{
	int option;
	do
	{
		printf("\n\n ***** MAIN MENU *****");
		printf("\n 1: create a list");
		printf("\n 2: Display a list");
		printf("\n 3: Add a node at the beginning");
 		printf("\n 4: Add a node at the end");
 		printf("\n 5: Add a node after a given node");
 		printf("\n 6: Delete a node from the beginning");
 		printf("\n 7: Delete a node from the end");
		printf("\n 8: Delete a node after a given node");
		printf("\n 9: Exit");
		printf("\n\n Enter your option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1: 
					start= create_dll(start);
					printf("\n Doubly linked list created.");
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
			 		start = insert_after(start);
 					break;
 			case 6: 	
			 		start = delete_beg(start);
 					break;
 			case 7: 
			 		start = delete_end(start);
 					break;
 			case 8: 
			 		start = delete_after(start);
 					break;		
		}
	}while(option != 9);
}

struct node* create_dll(struct node* start)
{
	struct node* newnode, *ptr;
	int val,n,i;
	printf("\n enter the number of nodes to store in a list: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("\n enter the data in the %d node: ",i);
		scanf("%d",&val);
		newnode= (struct node*)malloc(sizeof(struct node));
		newnode->data=val;
		if(start==NULL)
		{
			newnode->next=NULL;
			newnode->prev=NULL;
			start=newnode;
		}
		else
		{
			ptr=start;
			while(ptr->next != NULL)
				ptr=ptr->next;
			ptr->next=newnode;
			newnode->next=NULL;
			newnode->prev=ptr;
		}
	}
	return start;
}

void display(struct node* start)
{
	struct node* ptr=start;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}

struct node *insert_beg(struct node *start)
{
	struct node *newnode;
	int val;
	printf("\n Enter the data : ");
	scanf("%d", &val);
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode -> data = val;
	start -> prev = newnode;
	newnode -> next = start;
	newnode -> prev = NULL;
	start = newnode;
	return start;
}

struct node *insert_end(struct node *start)
{
	struct node *ptr, *newnode;
	int val;
	printf("\n Enter the data : ");
	scanf("%d", &val);
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode -> data = val;
	ptr=start;
	while(ptr -> next != NULL)
 		ptr = ptr -> next;
	ptr -> next = newnode;
	newnode -> prev = ptr;
	newnode -> next = NULL;
	return start;
}

struct node *insert_after(struct node *start)
{
	struct node *newnode, *ptr;
	int num, val;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	printf("\n Enter the value after which the data has to be inserted:");
	scanf("%d", &val);
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode -> data = num;
	ptr = start;
	while(ptr -> data != val)
 		ptr = ptr -> next;
	newnode -> prev = ptr;
	newnode -> next = ptr -> next;
	ptr -> next -> prev = newnode;
	ptr -> next = newnode;
	return start;
}

struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr = start;
	start = start -> next;
	start -> prev = NULL;
	free(ptr);
	return start;
}

struct node *delete_end(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr -> next != NULL)
 		ptr = ptr -> next;
	ptr -> prev -> next = NULL;
	free(ptr);
	return start;
}

struct node *delete_after(struct node *start)
{
	struct node *ptr, *temp;
	int val;
	printf("\n Enter the value after which the node has to deleted : ");
	scanf("%d", &val);
	ptr = start;
	while(ptr -> data != val)
 		ptr = ptr -> next;
	temp = ptr -> next;
	ptr -> next = temp -> next;
	temp -> next -> prev = ptr;
	free(temp);
	return start;
}
