#include<stdio.h>
#define INF 9999

int min(int a, int b);
int cost[10][10], adj[10][10];
inline int min(int a, int b){
   return (a<b)?a:b;
}
void main() {
   int vert, edge, i, j, k, c;
   printf("Enter no of vertices: ");
   scanf("%d",&vert);
   printf("Enter no of edges: ");
   scanf("%d",&edge);
   printf("Enter the EDGE Costs:\n");
   for (k = 1; k <= edge; k++) { //take the input and store it into adj and cost matrix
     scanf("%d %d %d",&i,&j,&c);
	
      adj[i][j] = cost[i][j] = c;
   }
   for (i = 1; i <= vert; i++)
      for (j = 1; j <= vert; j++) {
         if (adj[i][j] == 0 && i != j)
            adj[i][j] = INF; //if there is no edge, put infinity
      }
   for (k = 1; k <= vert; k++)
      for (i = 1; i <= vert; i++)
         for (j = 1; j <= vert; j++)
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]); //find minimum path from i to j through k
 
   printf("Resultant adj matrix\n");
   for (i = 1; i <= vert; i++) {
      for (j = 1; j <= vert; j++) {
            if (adj[i][j] != INF)
    
		printf("%d ",adj[i][j]); 
		   
      }
      printf("\n");
  
   }
}
