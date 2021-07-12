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

void NextValue(int G[MAX][MAX], int k,int n){
	int i,j;
	while(true){
		x[k] = (x[k]+1)%(n+1);
		
		if(x[k]==0)
			return;
		if(G[x[k-1]][x[k]]!=0){
			for(i=1;i<k;i++){
				if(x[i]==x[k])
					break;
			}
			if(i==k){
				if((k<n) || ((k==n) && G[x[n]][x[1]]!=0)){
					return;
				}
			}
		}
	}
}

void Hamiltonian(int G[MAX][MAX], int k, int n){
	while(true){
		NextValue(G,k,n);
		
		if(x[k]==0)
			return;
		if(k==n)
			display(n);
		else
			Hamiltonian(G,k+1,n);
	}
}

int main(){
	int n,i,j,G[MAX][MAX];
	printf("enter the no. of vertices:");
	scanf("%d",&n);
	
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
	
	Hamiltonian(G,1,n);
	printf("total no. of solutions: %d",count);
	
	getch();
	return 0;
}
