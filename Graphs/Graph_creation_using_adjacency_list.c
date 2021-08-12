// C program to represent a graph using an adjacency list
#include <stdio.h>
#include <malloc.h>

struct node
{
int vertex;
struct node *next;
};

void create_graph(struct node **, int );
void display(struct node **, int );

void main()
{
	struct node *Adj[10];
	int i, n, option;
	do
	{
		printf("\n\n *** MAIN MENU *** ");
		printf("\n1. Create a graph");
		printf("\n2. Display a graph");
		printf("\n3. Exit");
		printf("\n\nEnter Your Choice:");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\n Enter the number of nodes in Graph: ");
				scanf("%d", &n);
				for(i = 1; i <= n; i++)
 					Adj[i] = NULL;
				create_graph(Adj, n); 
				break;
			case 2:
				printf("\n The graph is: ");
				display(Adj, n);
            	break;
        }
	}while(option!=3);
}
	
	
void create_graph(struct node *Adj[], int n)
{
	struct node *new_node, *last;
	int i, j, k, val;
	for(i = 1; i <= n; i++)	
	{
 		last = NULL;
 		printf("\n Enter the number of neighbours of %d: ", i);
 		scanf("%d", &k);
 		for(j = 1; j <= k; j++)
 		{
 			printf("\n Enter the neighbour %d of %d: ", j, i);
 			scanf("%d", &val);
 			new_node = (struct node *) malloc(sizeof(struct node));
 			new_node -> vertex = val;
 			new_node -> next = NULL;
 			if (Adj[i] == NULL)
 				Adj[i] = new_node;
 			else
 				last -> next = new_node;
 				last = new_node;
 		}
	}	
}

void display(struct node *Adj[], int n)
{
	struct node *ptr;
	int i;
	for(i = 1; i <= n; i++)
	{
 		ptr = Adj[i];
 		printf("\n |%d|", i);
 		while(ptr != NULL)
 		{
 			printf(" --> %d", ptr -> vertex);
 			ptr = ptr -> next;
 		}
	}
}
