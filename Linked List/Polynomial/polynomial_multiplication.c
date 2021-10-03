#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coeff;
	int expo;
	struct node* next;
};
// structure variable declaration
struct node* start1 = NULL;
struct node* start2 = NULL;
struct node* start3 = NULL;
struct node* start4 = NULL;
//function prototypes
struct node* create_poly(struct node *);
void display_poly(struct node *);
struct node* mul_poly(struct node*, struct node*, struct node*);
struct node *add_node(struct node *, int, int);
struct node * add_coeff(struct node*);
void main()
{
	int option;
	do
	{
		printf("\n******* MAIN MENU *******");
		printf("\n 1. Enter the first polynomial");
		printf("\n 2. Display the first polynomial");
 		printf("\n 3. Enter the second polynomial");
 		printf("\n 4. Display the second polynomial");
 		printf("\n 5. multiply the polynomials");
 		printf("\n 6. Display the multiplication result");
 		printf("\n 7. Add the coefficients of same exponents");
 		printf("\n 8. Display the final result");
		printf("\n 9. EXIT");
 		printf("\n\n Enter your option : ");
 		scanf("%d", &option);
		switch(option)
 		{
 			case 1: start1 = create_poly(start1);
 			break;
 			case 2: display_poly(start1);
 					break;
 			case 3: start2 = create_poly(start2);
 					break;
 			case 4: display_poly(start2);
 					break;
 			case 5: start3 = mul_poly(start1, start2, start3);
 					break;
 			case 6: display_poly(start3);
 					break;
 			case 7: start4 = add_coeff(start3);
 					break;
 			case 8: display_poly(start4);
 					break;
 		}
	}while(option != 9);
}
// this function is used to create a polynomial
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
// this function is used to display the polynomial
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
// this function is used to multiply the two polynomials
struct node * mul_poly(struct node *start1, struct node *start2, struct node *start3)
{
	struct node *p=start1, *q=start2;
	while(p!=NULL)
	{
		while(q!=NULL)
		{
			start3=add_node(start3,p->coeff * q->coeff,p->expo + q->expo);
			q=q->next;
		}
		p=p->next;
		q=start2;
	}
return start3;
}
// this function is used to add the node of the multply result to the 
// new list in descending order.
struct node *add_node(struct node *start3, int co, int ex)
{
struct node *ptr, *new_node;
new_node = (struct node *)malloc(sizeof(struct node));
 new_node -> coeff = co;
 new_node -> expo = ex;
if(start3 == NULL || ex > start3->expo)
{
 new_node -> next = NULL;
 start3 = new_node;
}
else
{
 ptr = start3;
 while(ptr -> next != NULL && ptr->next->expo >= ex )
 	ptr = ptr -> next;
 new_node -> next = ptr->next;
 ptr -> next = new_node;
}
return start3;
}
//this function is used to add coefficients of same exponents
// of the polynomial to a new list.
struct node* add_coeff(struct node *start3)
{
	struct node *ptr1, *ptr2;
	ptr1=start3;
	ptr2=ptr1->next;
	while(ptr2 != NULL)
	{
		if(ptr1->expo == ptr2->expo)
		{
			start4=add_node(start4,ptr1->coeff+ptr2->coeff,ptr1->expo);
			ptr2=ptr2->next->next;
			ptr1=ptr1->next->next;
		}
		else
		{
			start4=add_node(start4, ptr1->coeff,ptr1->expo);
			ptr2=ptr2->next;
			ptr1=ptr1->next;
		}
	 }
	 start4=add_node(start4, ptr1->coeff,ptr1->expo);
	 return start4;
}
