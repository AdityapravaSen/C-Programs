#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(){
	
	int i,n=100,j;
	
	for(i=0;i<5;i++){
		
		for(j=0;j<10;j++){
			printf("%d\t",rand()%100);
		}
		printf("\n");
	}
}
