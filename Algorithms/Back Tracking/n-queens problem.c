#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int board[20],count=0;

void display(int n){
	int i;
	count++;
	printf("Solution %d:\n",count);
	for(i=1;i<=n;i++){
		printf("%d\t",board[i]+1);
	}
	printf("\n");
}

bool place(int k,int i){
	int j;
	for(j=1;j<=k-1;j++){
		if((board[j]==i) || (abs(board[j]-i)==abs(j-k))){
			return false;
		}
	}
	return true;
}

void NQueen(int k,int n){
	int i;
	for(i=0;i<n;i++){
		if(place(k,i)){
			board[k]=i;
			if(k==n){
				display(n);
			}else{
				NQueen(k+1,n);
			}
		}
	}
}

int main(){
	int n,i,j;
	printf("enter the no. of queens:");
	scanf("%d",&n);
	
	NQueen(1,n);
	printf("total no. of solutions: %d",count);
}
