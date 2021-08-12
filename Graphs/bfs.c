// C program to implement BFS by using recursion
#include<stdio.h>

int graph[20][20],queue[20],visited[20],n,f=-1,r=-1;

void bfs(int );

void main()
{
    int v,i,j;
    printf("\n Enter the number of vertices:");
    scanf("%d",&n);
    for (i=1;i<=n;i++)    
    {
        visited[i]=0;
    }
    printf("\n Enter graph data in matrix form:\n");
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
       scanf("%d",&graph[i][j]);
       
    printf("\n Enter the starting vertex:");
    scanf("%d",&v);
    f=r=0;
    queue[r]=v;
    
	printf("\n BFS traversal is:\n");
    visited[v]=1;   // mark the starting vertex as visited
    printf("%d   ",v);
   
    bfs(v);
    if(r != n-1)
        printf("\n BFS is not possible");
}

void bfs(int v) 
{
       int i;
       // check all the vertices in the graph
       for (i=1;i<=n;i++)                                
       {
       	
       	// adjacent to v and not visited
               if(graph[v][i] != 0 && visited[i] == 0) 
              {
                       r=r+1;
                       queue[r]=i;      // insert them into queue
                       visited[i]=1;    // mark the vertex visited
                       printf("%d  ",i);
              }
      }
      f=f+1;      // remove the vertex at front of the queue
      if(f<=r)    // as long as there are elements in the queue
            bfs(queue[f]);  // peform bfs again on the vertex at front of the queue
}
