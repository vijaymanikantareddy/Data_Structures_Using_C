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
void main()
{
	int option,size;
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
    			printf("enter the size of list :");
				scanf("%d",&size);
    			start=createll(start,size);
    			printf("\n linked list is created");
    			break;
    	    case 2:
			    display(start);
			    break;    
		}
	}while(option != 3);
	
}
struct node * createll(struct node*start, int size)
{
	struct node*newnode,*ptr;
	int i,n;
	printf("enter %d elements: ",size);
	for(i=0; i<size ; i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&n);;
		if(start==NULL)
		{
			start=newnode;
			newnode->data=n;
			newnode->next=start;
		}
		else
		{
			ptr=start;
			newnode->data=n;
		   	while(ptr->next!=start)
		   		ptr=ptr->next;
		   	ptr->next=newnode;
		   	newnode->next=start;
		}
	}
	return start;
}
 void display(struct node*start)
{
	struct node*ptr;
	ptr=start;
	while(ptr->next!=start)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("%d",ptr->data);
}
