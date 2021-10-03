#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coeff;
	int expo;
	struct node* next;
};
struct node* start = NULL;
struct node* create_poly(struct node *);
void display_poly(struct node *);
void main()
{
	int option;
	do
	{
		printf("\n\n *****MAIN MENU *****");
 		printf("\n 1: Create a polynomial list");
 		printf("\n 2: Display the polynomial list");
		printf("\n 3: Exit");
		printf("\nenter your option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				start = create_poly(start);
				printf("\n polynomial linked list is created");
				break;
			case 2:
				display_poly (start);
				break;
		}
	}while(option != 3);
}

struct node *create_poly(struct node *start)
{
struct node *new_node, *ptr;
int n, c,terms,i;
printf("\n enter the number of terms of the polynomial: ");
scanf("%d",&terms);
for(i=0;i<terms;i++)
{
	printf("\n Enter the coefficient number : ");
	scanf("%d", &n);
	printf("\t Enter its exponent : ");
	scanf("%d", &c);
 	new_node = (struct node *)malloc(sizeof(struct node));
 	new_node -> coeff = n;
 	new_node -> expo = c;
 	if(start==NULL)
 	{ 
 		new_node -> next = NULL;
 		start = new_node;
 	}
 	else
 	{
 		ptr = start;
 		while(ptr -> next != NULL)
			ptr = ptr -> next;
 		new_node -> next = NULL;
 		ptr -> next = new_node;
 	}
 
}
return start;
}

void display_poly(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr != NULL)
	{
 		printf("\n%d x^ %d\t", ptr -> coeff, ptr -> expo);
 		ptr = ptr -> next;
	}
	
}
