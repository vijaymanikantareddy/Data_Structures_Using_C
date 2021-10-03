#include <stdio.h>
#include <stdlib.h>
struct node
{
 int data;
 struct node *next;
};
struct node *start = NULL;
struct node *create_cll(struct node *);
void display(struct node *);
struct node* delete_beg(struct node *);
struct node* delete_end(struct node *);
struct node* delete_sp(struct node*);
void main()
{
 	int option;
 	do
 	{
		printf("\n\n *****MAIN MENU *****");
		printf("\n 1: Create a list");
		printf("\n 2: Display the list");
		printf("\n 3: Delete a node from the beginning");
		printf("\n 4: Delete a node from the end");
		printf("\n 5: Delete a node at a specific position");
		printf("\n 6: EXIT");
		printf("\n\n Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
 			case 1: start = create_cll(start);
 					printf("\n CIRCULAR LINKED LIST CREATED");
 					break;
 			case 2: display(start);
 					break;
 			case 3: start= delete_beg(start);
 					break;
 			case 4: start= delete_end(start);
 					break;
 			case 5: start= delete_sp(start);
 					break;		
		}
 	}while(option !=6);
}

struct node *create_cll(struct node *start)
{
	struct node *new_node, *ptr;
 	int num,n,i;
 	printf("enter the number of nodes to store in the linked list: ");
 	scanf("%d",&n);
 	for(i=1;i<=n;i++)
 	{
 		printf("enter the data in the %d node: ",i);
 		scanf("%d",&num);
 		new_node = (struct node*)malloc(sizeof(struct node));
 		new_node -> data = num;
 		if(start == NULL)
 		{
 			start = new_node;
 			new_node -> next = start;
 			
 		}
 		else
 		{ 
		 	ptr = start;
 			while(ptr -> next != start)
 				ptr = ptr -> next;
 			ptr -> next = new_node;
 			new_node -> next = start;
 		}
	}
	return start;
}
void display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr -> next != start)
	{
 		printf("\t %d", ptr -> data);
 		ptr = ptr -> next;
	}
	printf("\t %d", ptr -> data);
}
struct node* delete_beg(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr -> next != start)
 		ptr = ptr -> next;
	ptr -> next = start -> next;
	free(start);
	start = ptr -> next;
	return start;
}

struct node* delete_end(struct node *start)
{
	struct node *ptr, *preptr;
	ptr = start;
	while(ptr -> next != start)
	{
 		preptr = ptr;
 		ptr = ptr -> next;
	}
	preptr -> next = start;
	free(ptr);
	return start;
}

struct node* delete_sp(struct node* start)
{
	struct node *ptr, *preptr;
	int i, pos;
	printf("enter the position: ");
	scanf("%d",&pos);
	ptr = start;
	for(i=1 ; i<pos ; i++)
	{
 		preptr = ptr;
 		ptr = ptr -> next;
	}
	preptr -> next = ptr->next;
	free(ptr);
	return start;
}
