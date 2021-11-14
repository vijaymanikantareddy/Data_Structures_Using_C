// C program to create a binary tree using linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node* left;
	int data;
	struct node* right;
};

struct node* root=NULL;

struct node* create();
void display(struct node*);

void main()
{
	root= create();
	printf("\n the elements in the binart tree is: ");
	display(root);
}

struct node* create()
{
	struct node* ptr;
	int num;
	printf("Enter the data (-1 for storing NULL): ");
	scanf("%d",&num);
	if(num == -1)
		return NULL;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=num;
	printf("Enter left child of %d:\n",num);
	ptr->left=create();
	printf("Enter right child of %d: \n", num);
	ptr->right=create();
	return ptr;	
}

void display(struct node* root)
{
	if(root!=NULL)
	{
		display(root->left);
		printf("%2d",root->data);
		display(root->right);
	}
}
