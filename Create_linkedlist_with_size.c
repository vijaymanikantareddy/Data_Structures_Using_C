#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * next;
};
struct node * start=NULL;
struct node * createll(struct node*);
void display(struct node*);
void main()
{
	int option;
	do
    {
    	printf("\n\n***MAIN MENU***");
    	printf("\nenter 1 : To create list.");
    	printf(" \nenter 2 : To display a list.");
    	printf("\nenter 3 : To exit.");
    	printf("\nenter the option :");
    	scanf("%d",&option);
    	switch(option)
    	{
    		case 1:
    			start=createll(start);
    			printf("\n linked list is created");
    			break;
    	    case 2:
			    display(start);
			    break;    
		}
	}while(option != 3);
	
}
struct node * createll(struct node*start)
{
	struct node*newnode,*ptr;
	int iter,i,n;
	printf("enter the size of list :");
	scanf("%d",&iter);
	for(i=0; i<iter ; i++)
	{
		printf("\n enter the data:");
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
