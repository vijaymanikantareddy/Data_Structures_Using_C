// c program to create a adjacency matrix
#include<stdio.h>
#include<stdlib.h>
#define max 20
int adj[max][max];
int n;

void create_graph();
void display();
void insert_node();
void delete_node(int);

int main()
{
	
	int node,option;
	do
	{
		printf("\n\n *** MAIN MENU *** ");
		printf("\n1. Create a graph");
		printf("\n2. Display a graph");
		printf("\n3. Insert a node into a graph");
		printf("\n4. Delete a node from a graph");
		printf("\n\nEnter Your Choice:");
		scanf("%d",&option);
		switch(option)
		{
			case 1: 
				create_graph();
				break;
			case 2:
				display();
            	break;
            case 3: 
				insert_node();
				break;
			case 4:
				printf("Enter a node to be deleted : ");
            	scanf("%d", &node);
            	delete_node(node);
            	break;
        }
	}while(option!=5);
return 0;
}

void create_graph() {
    int i, max_edges, origin, destin;
 
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    max_edges = n * (n - 1);
 
    for (i = 1; i <= max_edges; i++) {
        printf("Enter edge %d( 0 0 ) to quit : ", i);
        scanf("%d %d", &origin, &destin);
        if ((origin == 0) && (destin == 0))
            break;
        if (origin > n || destin > n || origin <= 0 || destin <= 0) {
            printf("Invalid edge!\n");
            i--;
        } else
            adj[origin][destin] = 1;
    }
}
 
void display() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%4d", adj[i][j]);
        printf("\n");
    }
}

void insert_node() {
    int i, max_edges, origin, destin;
    n++;
    printf("The inserted node is %d \n", n);
    for (i = 1; i <= n; i++) {
        adj[i][n] = 0;
        adj[n][i] = 0;
    }
    
    max_edges = n + n - 1;
 
    for (i = 1; i <= max_edges; i++) {
        printf("Enter edge %d( 0 0 ) to quit : ", i);
        scanf("%d %d", &origin, &destin);
        if ((origin == 0) && (destin == 0))
            break;
        if (origin > n || destin > n || origin <= 0 || destin <= 0) {
            printf("Invalid edge!\n");
            i--;
        } else
            adj[origin][destin] = 1;
    }
}



void delete_node(int u) {
    int i, j;
    if (n == 0) {
        printf("Graph is empty\n");
        return;
    }
    if (u > n) {
        printf("This node is not present in the graph\n");
        return;
    }
    for(i=node ; i<=n-1;i++)
    for(j=1;j<=n ;j++)
	{
		if(i==j)
			graph[i][j]=0;
		else
		{
			graph[j][i]=graph[j][i+1];
			graph[i][j]=graph[i+1][j];	
		}
	}
    n--;
}
