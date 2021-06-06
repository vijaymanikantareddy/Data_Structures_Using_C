/* Sparse Matrix Creation*/  
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int row;
	int column;
	int val;
	struct node* next;
};
struct node* start= NULL;
struct node* create_sll(struct node* start, int row, int column, int val );
void display(struct node* start);

void main()
{
	int i,j,m,n;
	printf("enter the row size and column size: ");
	scanf("%d %d",&m,&n);
	int sparsematrix[m][n];
	printf("enter the elements: ");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&sparsematrix[i][j]);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(sparsematrix[i][j]!=0)
				start= create_sll(start, i, j, sparsematrix[i][j]);
	
	display(start);
}

struct node* create_sll(struct node* start, int r, int c, int v)
{
	struct node* new_node, *ptr;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->row=r;
	new_node->column=c;
	new_node->val=v;
	if(start==NULL)
	{
		new_node->next=NULL;
		start=new_node;
	}
	else
	{
		ptr=start;
		while(ptr->next != NULL)
			ptr=ptr->next;
		ptr->next=new_node;
		new_node->next=NULL;	
	}
	return start;
}

void display(struct node* start)
{
	struct node* ptr=start;
	printf("row   : ");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->row);
		ptr=ptr->next;
	}
	printf("\n");
	ptr=start;
	printf("column: ");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->column);
		ptr=ptr->next;
	}
	printf("\n");
	ptr=start;
	printf("values: ");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->val);
		ptr=ptr->next;
	}
}
