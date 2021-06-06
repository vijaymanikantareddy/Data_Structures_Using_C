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
void searching(struct node*start);
void main()
{
	int option;
	do
    {
    	printf("\n\n***MAIN MENU***");
    	printf("\nenter 1 : To create list.");
    	printf(" \nenter 2 : To display a list.");
    	printf("\n enter 3 : To searching a value in list");
    	printf("\nenter 4 : To exit.");
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
			case 3:
			    searching(start);
				break;    
		}
	}while(option != 4);
}

struct node * createll(struct node*start)
{
	struct node*newnode,*ptr;
	int num;
	printf("enter the data or -1 to end :");
	scanf("%d",&num);
	while(num!=-1)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=num;
		if(start==NULL)
		{
			newnode->next=NULL;
			start=newnode;
		}
		else
		{
		   ptr=start;
		   while(ptr->next!=NULL)
		   ptr=ptr->next;
		   ptr->next=newnode;
		   newnode->next=NULL;
		}
		printf("\n enter the data:");
		scanf("%d",&num);
	}
	return start;
}

 void display(struct node*start)
{
	struct node*ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}

}

void searching(struct node*start)
{
	int flag=-1,val;
    struct node*ptr;
    ptr=start;
    printf("enter the item:");
    scanf("%d",&val);
    while(ptr!=NULL && ptr->data!=val)
    {
       flag++;
       ptr=ptr->next;
	}
    if(flag>-1 || ptr->data==val)
    	printf("%d is found in the linked list.",val);
    else
	    printf("%d is not found in the linked list",val);
}
