// C program to implement DFS using recursion
#include<stdio.h>

int graph[10][10],visited[10],n;
 
void DFS(int);
    
void main()
{
    int i,j,v;
    printf("Enter number of vertices:");
  	scanf("%d",&n);
    printf("\nEnter adjecency matrix of the graph:\n");
  	for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
			scanf("%d",&graph[i][j]);
    //visited is initialized to zero
    for(i=1;i<=n;i++)
        visited[i]=0;
    printf("\n enter the starting vertex: ");
    scanf("%d",&v);
    DFS(v);
}

void DFS(int v)
{
    int i;
	printf("%4d",v);
    visited[v]=1;
	for(i=1;i<=n;i++)
       	if(!visited[i]&&graph[v][i]==1)
            DFS(i);
}
