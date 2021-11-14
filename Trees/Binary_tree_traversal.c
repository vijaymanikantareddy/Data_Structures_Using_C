// A recursive C program for traversing a binary tree in preorder, inorder and postorder.
#include<stdio.h>
#include<stdlib.h>
 
struct node
{
char data;
struct node *left;
struct node *right;
};

struct node *root=NULL;

struct node *create();
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);

void main()
{

int option;
	do
	{
 		printf("\n\n *****MAIN MENU*****");
 		printf("\n 1. create a binary tree ");
 		printf("\n 2. In-order traversal");
 		printf("\n 3. Pre-order traversal");
 		printf("\n 4. Post-order traversal");
 		printf("\n 5. EXIT");
 		printf("\n Enter your option : ");
 		scanf("%d", &option);
		switch(option)
 		{
 			case 1:
 				root = create();
 				break;
 			case 2:
 				printf("\n the elements after inorder traversal:  ");
 				inorder(root);
 				break;
 			case 3:
 				printf("\n the elements after preorder traversal:  ");
 				preorder(root);
 				break;
 			case 4:
 				printf("\n the elements after postorder traversal:  ");
				postorder(root);
				break;
 		}
	}while(option != 5);
}

struct node *create()
{
	struct node *p;
	char x;
	printf("Enter data(0 for no data):");
	scanf(" %c",&x);
	if(x=='0')
		return NULL;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=x;
	printf("Enter left child of %c:\n",x);
	p->left=create();
	printf("Enter right child of %c:\n",x);
	p->right=create();
	return p;
}
 
void inorder(struct node *root)
{
  if(root!=NULL)
  {
	  inorder(root->left);
	  printf(" %2c",root->data);
	  inorder(root->right);
  }
}

void preorder(struct node *root)
{
  if(root!=NULL)
  {
	  printf(" %2c",root->data);
	  preorder(root->left);
	  preorder(root->right);
  }
}

void postorder(struct node *root)
{
  if(root!=NULL)
  {
	  postorder(root->left);
	  postorder(root->right);
	  printf(" %2c",root->data);
  }
}
