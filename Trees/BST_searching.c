// C program to search a given key in a given BST
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
};

struct node *root=NULL;

struct node *create(struct node *);
void display(struct node *);
struct node* search(struct node*, int);

void main()
{
	int option,val;
	do
	{
		printf("\n\n *** MAIN MENU *** ");
		printf("\n 1.create");
		printf("\n 2.display");
		printf("\n 3.search");
		printf("\n 4.Quit");
		printf("\n Enter your choice\n");
		scanf("%d",&option);
		switch (option)
		{
			case 1:
				root = create(root);
				break;
			case 2: 
				printf("\n The elements in the tree are\n");
				display(root);
				break;
			case 3:
				printf("\n enter the element which you want to search: ");
				scanf("%d",&val);
				root=search(root, val);
				if(root==NULL)
					printf("\n element not found in a BST");
				else 
					printf("\n element found in a BST");
				break;
		}
	}while(option<4);
}

struct node* create(struct node* root)
{
	int val;
	printf("\n enter data (-1 to stop)");
	scanf("%d",&val);
	while(val != -1)
	{
	struct node *ptr, *nodeptr, *parentptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;
	if(root==NULL)
	{
		root=ptr;
	}
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
				nodeptr = nodeptr->right;
		}
		if(val<parentptr->data)
			parentptr->left = ptr;
		else
			parentptr->right = ptr;
	}
	printf("\n enter data (-1 to stop)");
	scanf("%d",&val);
}
	return root;
}

void display(struct node *root)
{
	if(root!=NULL)
	{
		display(root->left);
		printf("\n %5d",root->data);
		display (root->right);
	}
}

struct node* search(struct node* root, int key)
{
	if (root == NULL || root->data == key)
		return root;
	if (root->data < key)
		return search(root->right, key);
	return search(root->left, key);
}
