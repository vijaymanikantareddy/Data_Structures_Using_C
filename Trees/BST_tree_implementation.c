// C program to implement a  binary search tree
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
struct node* search(struct node*, int);
struct node* insert(struct node*, int);
struct node* delete_node(struct node*, int);
struct node* findminvalue(struct node*);
int height (struct node*);
int totalnodes(struct node*);
int totalinternalnodes(struct node*);
int totalexternalnodes(struct node*);
void mirrorImage(struct node *);
struct node *findSmallestElement(struct node *);
struct node *findLargestElement(struct node *);
struct node *deleteTree(struct node *);

void main()
{
	int option, val;
	struct node* ptr;
	do
	{
		printf("\n\n *** MAIN MENU ***");
		printf("\n 1. create a BST");
		printf("\n 2. display a BST");
		printf("\n 3. search a node in a BST");
		printf("\n 4. Insert a node into a BST");
		printf("\n 5. Delete a node from a BST");
		printf("\n 6. height of a BST");
		printf("\n 7. total number of nodes in a BST");
		printf("\n 8. total number of internal nodes in a BST");
		printf("\n 9. total number of external nodes in a BST");
		printf("\n 10. Find the mirror image of a BST");
		printf("\n 11. smallest node in a BST");
		printf("\n 12. largest node in a BST");
		printf("\n 13. delete a BST");
		printf("\n 14. Quit");
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
			case 3:
				printf("\n enter a value which you want to search: ");
				scanf("%d",&val);
				root=search(root,val);
				if(root==NULL)
					printf("\n Value not found in a BST");
				else
					printf("\n value found in a BST");
				break;
			case 4:
				printf("\n enter an element to insert in BST: ");
				scanf("%d",&val);
				root=insert(root, val);
				break;
			case 5:
				printf("\n enter a value to delete from a BST: ");
				scanf("%d", &val);
				root=delete_node(root, val);
				break;
			case 6:
				printf("\n the height of a BST: %d",height(root));
				break;
			case 7:
				printf("\n total number of nodes in a BST: %d",totalnodes(root));
				break;
			case 8:
				printf("\n total number of internal nodes in a BST: %d",totalinternalnodes(root));
				break;
			case 9:
				printf("\n total number of external nodes in a BST: %d",totalexternalnodes(root));
				break;
			case 10:
				mirrorImage(root);
				break;
			case 11:
				ptr = findSmallestElement(root);
				printf("\n Smallest element is :%d",ptr->data);
				break;
			case 12:
				ptr = findLargestElement(root);
				printf("\n Largest element is : %d", ptr->data);
				break;
			case 13:
				root = deleteTree(root);
				break;
		}
	}while(option<14);
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

struct node* search(struct node* root, int val)
{
	if(root==NULL || root->data==val)
		return root;
	else if(val < root->data)
		return search(root->left,val);
	else return search(root->right,val);
}

struct node* insert(struct node* root, int val)
{
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node));
		root->data=val;
		root->left=root->right=NULL;
		return root;
	}
	else if(val<root->data)
		root->left=insert(root->left,val);
	else
		root->right=insert(root->right,val);
	return root;
}

struct node* delete_node(struct node* root, int val)
{
	if(root==NULL)
		return root;
	// If the val to be deleted is smaller than the root go to left subtree,
	if(val<root->data)
		root->left=delete_node(root->left, val);
	// If the val to be deleted is greater than the root go to right subtree,
	else if(val>root->data)
		root->right=delete_node(root->right, val);
	else
	{
		//a node with one child or null
		if(root->left==NULL)
		{
			struct node* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct node* temp=root->left;
			free(root);
			return temp;
		}
		// a node with two child
		struct node* temp=findminvalue(root->right);
		root->data=temp->data;
		root->right=delete_node(root->right,temp->data);
	}
	return root;
}

struct node* findminvalue(struct node* ptr)
{
	struct node* current=ptr;
	while(current->left!=NULL)
		current = current->left;
	return current;
}

int height(struct node* root)
{
	int leftheight, rightheight;
	if(root==NULL)
		return 0;
	else
	{
		leftheight=height(root->left);
		rightheight=height(root->right);
		if(leftheight>rightheight)
			return leftheight+1;
		else return rightheight+1;
	}
}

int totalnodes(struct node* root)
{
	if(root==NULL)
		return 0;
	else
		return (totalnodes(root->left)+totalnodes(root->right)+1);
}

int totalinternalnodes(struct node* root)
{
	if((root==NULL)||(root->left==NULL && root->right==NULL))
		return 0;
	else
		return (totalinternalnodes(root->left)+totalinternalnodes(root->right)+1);
}

int totalexternalnodes(struct node* root)
{
	if(root==NULL)
		return 0;
	else if(root->left==NULL && root->right==NULL)
		return 1;
	else
		return (totalexternalnodes(root->left)+totalexternalnodes(root->right));
}


void mirrorImage(struct node *root)
{
	struct node *ptr;
	if (root == NULL) {
        return;
    }
    else
	{
		mirrorImage(root->left);
		mirrorImage(root->right);
		ptr=root->left;
		root->left = root->right;
		root->right = ptr;
	}
	
}

struct node *findSmallestElement(struct node *root)
{
	if( (root == NULL) || (root->left == NULL))
		return root;
	else
		return findSmallestElement(root->left);
}

struct node *findLargestElement(struct node *root)
{
	if( (root == NULL) || (root->right == NULL))
		return root;
	else
		return findLargestElement(root->right);
}

struct node *deleteTree(struct node *root)
{
	if(root!=NULL)
	{
		deleteTree(root->left);
		deleteTree(root->right);
		free(root);
	}
}
