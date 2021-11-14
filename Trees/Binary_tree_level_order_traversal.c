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
void printgivenlevel(struct node* root, int level);
int height(struct node* node);
void printlevelorder(struct node* root);

void main()
{
	root= create();
	printf("\n the elements in the binart tree is: ");
	printlevelorder(root);
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

//used to find the height of the tree
int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

/* Function to print level order traversal a tree*/
void printlevelorder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printgivenlevel(root, i);
}
 
/* Print nodes at a given level */
void printgivenlevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printgivenlevel(root->left, level-1);
        printgivenlevel(root->right, level-1);
    }
}
