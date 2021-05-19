#include<stdio.h>
int check(int m,int n,int a[m][n]){
	int c=0,i,j;
	
	for(i=0;i<m;i++){
		if(i%2==0){
			for(j=0;j<n-1;j++){
				
				if(a[i][j+1]>=a[i][j]){
					c++;
				}else
					return 0;
			}
			
			if(i==m-1)
				return c;
			if(a[i][j]<=a[i+1][j]){
				c++;
			}else{
				return 0;
			}
		}
		else{
			for(j=n-1;j>0;j--){
				if(a[i][j-1]>=a[i][j]){
					c++;
				}
				else
					return 0;
			}
			
			if(i==m-1)
				return c;
			if(a[i][j]<=a[i+1][j]){
				c++;
			}
			else{
				return 0;
			}
		}
	}
	return c;
}
main(){
	int m,n,i,j,temp,k,d;
	
	printf("\nEnter the number of rows");
	scanf("%d",&m);
	printf("\nEnter the number of column\n");
	scanf("%d",&n);
	int arr[m][n];
	
	printf("\nenter the elements in the array");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	
	printf("\nThe matrix is\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	d=check(m,n,arr);
	while(d!=(m*n)-1){
		for(i=0;i<n;i++){
			if(i%2==0){
				for(j=0;j<m;j++){
					for (k=0;k<n-j-1;k++)
						if(arr[i][k]>arr[i][k+1]){
							temp=arr[i][k];
							arr[i][k]=arr[i][k+1];
							arr[i][k+1]=temp;
						}
				}
			}
			if(i%2!=0){
				for(j=0;j<m;j++){
					for (k=0;k<n-j-1;k++)
						if(arr[i][k]<arr[i][k+1]){
							temp=arr[i][k];
							arr[i][k]=arr[i][k+1];
							arr[i][k+1]=temp;
						}
				}
			}
		}
		for (j=0;j<n;j++) {
			for (i=0;i<m;i++) {
				for (k=0;k<m-1-i;k++) {
					if (arr[k][j] > arr[k+1][j]) {
						temp=arr[k+1][j];
						arr[k+1][j]=arr[k][j];
						arr[k][j]=temp;
					}
				}
			}
		}
		d=check(m,n,arr);
	}
	
	printf("\n required matrix is:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
}
