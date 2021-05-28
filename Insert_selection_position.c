#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * next;
};
struct node * start=NULL;
struct node * createll(struct node*, int);
void display(struct node*);
struct node * insert(struct node*, int value, int pos);
void main()
{
	int option,iter,value,pos;
	do
    {
    	printf("\n\n***MAIN MENU***");
    	printf("\nenter 1 : To create list.");
    	printf(" \nenter 2 : To display a list.");
    	printf("\nenter 3 : insert at a specific position");
    	printf("\nenter 4 : exit");
    	printf("\nenter the option :");
    	scanf("%d",&option);
    	switch(option)
    	{
    		case 1:
    			printf("enter the size of list :");
				scanf("%d",&iter);
    			start=createll(start,iter);
    			printf("\n linked list is created");
    			break;
    	    case 2:
			    display(start);
			    break;  
			case 3:
				printf("enter value & position: ");
				scanf("%d %d",&value,&pos);
				start=insert(start, value, pos);	  
		}
	}while(option != 4);
	
}
struct node * createll(struct node*start, int iter)
{
	struct node*newnode,*ptr;
	int i,n;
	printf("enter %d elements: ",iter);
	for(i=0; i<iter ; i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&n);;
		if(start==NULL)
		{
			start=newnode;
			newnode->data=n;
			newnode->next=NULL;
		}
		else
		{
			ptr=start;
			newnode->data=n;
		   	while(ptr->next!=NULL)
		   		ptr=ptr->next;
		   	ptr->next=newnode;
		   	newnode->next=NULL;
		}
	}
	return start;
}
 void display(struct node*start)
{
	struct node*ptr;
	ptr=start;
	if(start==NULL)
	{
		printf("List does not exist!");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
}
struct node* insert(struct node* start, int value, int pos)
{
	struct node *newnode, *ptr, *preptr;
	int i;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	ptr=start;
	if(pos==0)
	{
		preptr=start;
		start=newnode;
		newnode->data=value;
		newnode->next=preptr;
	}
	else
	{
		for(i=0; i<pos; i++)
		{
			ptr=ptr->next;
		}
		preptr=ptr->next;
		ptr->next=newnode;
		newnode->next=preptr;
	}
	return start;
}
