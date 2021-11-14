// C program to create a binary search tree
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left, *right;
};

struct node* root = NULL;

struct node *create(struct node* );
void display(struct node* );

void main()
{
	int option, val;
	do
	{
		printf("\n\n *** MAIN MENU ***");
		printf("\n 1. create");
		printf("\n 2. display");
		printf("\n 3. exit");
		printf("\n enter your choice: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				root = create(root);
				break;
			case 2:
				printf("\n the elements in the BST: ");
				display(root);
				break;
		}
	}while(option<3);
}

struct node* create(struct node* root)
{
	int val;
	printf("\n enter data (-1 to stop): ");
	scanf("%d",&val);
	while(val != -1)
	{
		struct node *ptr, *nodeptr, *parentptr;
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=val;
		ptr->left=NULL;
		ptr->right=NULL;
		if(root==NULL)
			root=ptr;
		else
		{
			parentptr=NULL;
			nodeptr=root;
			while(nodeptr!=NULL)
			{
				parentptr=nodeptr;
				if(val<nodeptr->data)
					nodeptr=nodeptr->left;
				else
					nodeptr=nodeptr->right;	
			}
			if(val<parentptr->data)
				parentptr->left=ptr;
			else
				parentptr->right=ptr;
		}
		printf("\n enter data (-1 to stop): ");
		scanf("%d",&val);
	}
	return root;
}

void display(struct node* root)
{
	if(root != NULL)
	{
		display(root->left);
		printf("%4d", root->data);
		display(root->right);
	}
}
