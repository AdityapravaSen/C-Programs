#include<stdio.h>
#define INF 9999
#define MAX 100

int min(int a,int b){
	if(a<b){
		return a;
	}else{
		return b;
	}
}

void floydWarshall(int matrix[MAX][MAX],int n){
	int i,j,k;
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i==j){
					matrix[i][j]=0;
				}else{
					matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
				}
			}
		}
	}
	printf("\nThe Shotest path Matrix is:\n");
	display(matrix,n);
}

void display(int mat[MAX][MAX],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int adjmat[MAX][MAX];
	int i,j,n,val;
	
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	
	//initializing array with infinity
	/*for(i=0;i<n;i++){
		for(j=1;j<=n;j++){
			adjmat[i][j]=INF;
		}
	}*/

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("Enter value for %d to %d:",i+1,j+1);
			scanf("%d",&val);
			adjmat[i][j]=val;
		}
	}
	
	printf("A0 is:\n");
	display(adjmat,n);
	
	floydWarshall(adjmat,n);
	
	return 0;
}
