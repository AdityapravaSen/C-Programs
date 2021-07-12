#include<stdio.h>
#define INF 999
#define MAX 100

void display(int mat[MAX][MAX],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
}

void bellman_ford(int v,int cost[MAX][MAX],int n){
	int i,k,u,dist[n];
	
	for(i=0;i<n;i++){
		dist[i]=cost[v][i];
	}
	dist[v]=0;
	for(k=0;k<n-1;k++){
		for(i=0;i<n;i++){
			for(u=0;u<n;u++){
				if(dist[u]>(dist[i]+cost[i][u]) && dist[i]!=INF){
					dist[u]=dist[i]+cost[i][u];
				}
			}	
		}
	}
	
	printf("\nSingle Source Shortest Path:\n");
	for(i=0;i<n;i++){
		printf("%d\t",dist[i]);
	}
}

int main(){
	int cost_mat[MAX][MAX],i,j,n;
	
	printf("enter the no. of vertices:");
	scanf("%d",&n);
	
	printf("enter cost matrix(999 for infinity):\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				cost_mat[i][j]=0;
			}else{
				printf("Enter value for %d to %d:",i+1,j+1);
				scanf("%d",&cost_mat[i][j]);
			}
		}
	}
	
	display(cost_mat,n);
	bellman_ford(0,cost_mat,n);
	
	fflush(stdin);
	return 0;
}
