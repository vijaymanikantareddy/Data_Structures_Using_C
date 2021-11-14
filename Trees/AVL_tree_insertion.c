//c program to insert a node into a AVL tree
#include<stdio.h>
#include<stdlib.h>

//every node contains a height
struct node
{
int data;
struct node *left,*right;
int ht;  // ht = height
};

struct node *root=NULL;
 
struct node *insert(struct node *,int);
void inorder(struct node *);
int height(struct node *);
struct node *rotateright(struct node *);
struct node *rotateleft(struct node *);
struct node *RR(struct node *);
struct node *LL(struct node *);
struct node *LR(struct node *);
struct node *RL(struct node *);
int Balancefactor(struct node *);
 
int main()
{
	
	int x,n,i,option;
	do
	{
	printf("\n\n *** MAIN MENU *** ");
	printf("\n1. Create a AVL tree");
	printf("\n2. Insert a new node into a AVL tree");
	printf("\n3. Display a AVL tree");
	printf("\n4. Exit");
	printf("\n\nEnter Your Choice:");
	scanf("%d",&option);
	switch(option)
	{
		case 1: 
			printf("\nEnter no. of elements:");
			scanf("%d",&n);
			printf("\nEnter tree data:");
			for(i=0;i<n;i++)
			{
				scanf("%d",&x);
				root=insert(root,x);
			}
			break;
		case 2: 
			printf("\nEnter a data:");
			scanf("%d",&x);
			root=insert(root,x);
			break;
		case 3: 
			printf("\nNodes of a AVl tree : ");
			inorder(root);
			break;
	}
	}while(option!=4);
return 0;
}
 
struct node * insert(struct node *root,int x)
{
	// when tree is empty
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node));
		root->data=x;
		root->left=NULL;
		root->right=NULL;
	}
	// tree is not empty
	else
	if(x > root->data) // insert in right subtree
	{
		root->right=insert(root->right,x);
		if(Balancefactor(root)==-2) //critcal node at right subtree
		if(x>root->right->data) //new node at right subtree
			root=RR(root);
		else      // new node at left subtree
			root=RL(root);   
	}
	else if(x<root->data) // insert at left subtree
	{
		root->left=insert(root->left,x);
		if(Balancefactor(root)==2)  //critcal node at left subtree
		if(x < root->left->data)   //new node at left subtree
			root=LL(root);
		else
			root=LR(root);   //new node at right subtree
	}
	root->ht=height(root);
	return(root);
}
  
// this function is used to find the height of a node
// height of a node is considered as max height of 
// left subtree and right subtree.
int height(struct node *root)
{
	int lh,rh;
	if(root==NULL)  // if no nodes in tree
		return(0);
	if(root->left==NULL)  // if node left child is null
		lh=0;
	else
		lh=1+root->left->ht; //adding the height of left subtree
	if(root->right==NULL)  // if node right child is null
		rh=0;
	else
		rh=1+root->right->ht; //adding the height of right subtree
	if(lh>rh)      // returning maximum height
		return(lh);
	return(rh);
}
 
//this function is used to rotate a critical node to right
struct node * rotateright(struct node *x)
{
	struct node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}

//this function is used to rotate a critical node to left
struct node * rotateleft(struct node *x)
{
	struct node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}
 
// this function is used to perform RR rotation 
// were the critical node is rotated to left
struct node * RR(struct node *root)
{
	root=rotateleft(root);
	return(root);
}
 
// this function is used to perform LL rotation 
// were the critical node is rotated to right
struct node * LL(struct node *root)
{
	root=rotateright(root);
	return(root);
}
 
// this function is used to perform LR rotation 
// were the critical node left chid is rotated to left
// and critical node is rotated to right
struct node * LR(struct node *root)
{
	root->left=rotateleft(root->left);
	root=rotateright(root);
	return(root);
}
 
// this function is used to perform RL rotation 
// were the critical node right chid is rotated to right
// and critical node is rotated to left
struct node * RL(struct node *root)
{
	root->right=rotateright(root->right);
	root=rotateleft(root);
	return(root);
}

//this function is used to perform balance factor 
int Balancefactor(struct node *root)
{
	int lh,rh;
	if(root==NULL)
		return(0);
 	if(root->left==NULL)
		lh=0;
	else
		lh=1+root->left->ht;
 
	if(root->right==NULL)
		rh=0;
	else
		rh=1+root->right->ht;
 
	return(lh-rh);
}
 
// this function is used to display the node in inorder
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d(Bf=%d)  ",root->data,Balancefactor(root));
		inorder(root->right);
	}
}
