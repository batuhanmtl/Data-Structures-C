#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define INF 999
#define max 10

int i,j,k,a,b,u,v,vertex_number,ne=1;
int min,mincost=0,cost[max][max],parent[max];
int find(int);
int uni(int,int);
main()
{
   	printf("\n\tImplementation of Kruskal's Algorithm\n");
   	printf("\nEnter the no. of vertices:");
   	scanf("%d",&vertex_number);
   	printf("\nEnter the cost adjacency matrix:\n");
   	for(i=1;i<=vertex_number;i++) // Creating Adjacency Matrix
   	{
   		for(j=1;j<=vertex_number;j++)
   		{	
   			printf("Adj[%d][%d] = ",i,j);
   			scanf("%d",&cost[i][j]);
   			if(cost[i][j]==0)
   			cost[i][j]=INF;
   		}
   	}
   	printf("The edges of Minimum Cost Spanning Tree are\n");
   	while(ne < vertex_number)
   	{
   		for(i=1,min=INF;i<=vertex_number;i++)
   		{
   			for(j=1;j <= vertex_number;j++)
   			{
   				if(cost[i][j] < min)
   					{
   						min=cost[i][j];
   						a=u=i;
   						b=v=j;
   					}
    		}
    	}
    	u=find(u);
    	v=find(v);
    	
    	if(uni(u,v))
    	{
    		printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
    		mincost +=min;
    	}
    	cost[a][b]=cost[b][a]=INF;
   	}
    printf("\n\tMinimum cost = %d\n",mincost);
    getch();
}
int find(int i)
{
    while(parent[i])
   	i=parent[i];
   	return i;
}
int uni(int i,int j)
{
   	if(i!=j)
    {
    	parent[j]=i;
    	return 1;
    }
    return 0;
}
