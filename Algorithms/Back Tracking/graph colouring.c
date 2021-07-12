#include<stdio.h>
#include<stdbool.h>
#define MAX 20

int x[MAX],count=0;

void display(int n){
	int i;
	count++;
	printf("Solution %d:\n",count);
	for(i=1;i<=n;i++){
		printf("%d\t",x[i]);
	}
	printf("\n");
}

void NextValue(int G[MAX][MAX],int k,int m, int n){
	int j;
	while(true){
		x[k]=(x[k]+1)%(m+1);
		
		if(x[k]==0)
			return;
			
		for(j=1;j<=n;j++){
			if((G[k][j]!=0) && (x[k]==x[j]))
				break;
		}
		if(j==n+1)
			return;
	}
}

void mColouring(int G[MAX][MAX], int k, int m, int n){
	while(true){
		NextValue(G,k,m,n);
		
		if(x[k]==0)
			return;
		if(k==n){
			display(n);
		}else{
			mColouring(G,k+1,m,n);
		}
	}
}

int main(){
	int n,i,j,m,G[MAX][MAX];
	printf("enter the no. of vertices:");
	scanf("%d",&n);
	printf("enter the no. of colours:");
	scanf("%d",&m);
	
	printf("\nenter adjacency matrix(1-edge present 0-not present):\n");
   	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){
				G[i][j]=0;
			}else{
				printf("from vertex %d to %d:",i,j);
   				scanf("%d",&G[i][j]);
			}
		}
	}
	
	mColouring(G,1,m,n);
	printf("total no. of solutions: %d",count);
	
	getch();
	return 0;
}
