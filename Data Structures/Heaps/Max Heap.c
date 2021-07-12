// insertion and deletion in max heap
#include<stdio.h>
#include<conio.h>
#define MAX 100

int arr[MAX], n;

void insert(int val){
	int i,parent,temp;
	if(n==0){
		arr[0]=val;
		n=n+1;
		printf("node inserted\n");
		return;
	}
	n=n+1;
	i=n-1;
	arr[i]=val;
	//i=n;
	
	while(i>0){
		parent=(i)/2;
		
		if(arr[parent]<arr[i]){
			temp=arr[parent];
			arr[parent]=arr[i];
			arr[i]=temp;
			
			i=parent;
		}else{
			printf("node inserted\n");
			return;
		}
	}
}

void del(){
	int last=arr[n-1],i=0,left=1,right=2,temp;
	arr[i]=arr[n-1];
	n=n-1;
	
	while(right<n){
		if(arr[i]>=arr[left] && arr[i]>=arr[right]){
			return;
		}
		if(arr[right]<=arr[left]){
			temp=arr[i];
			arr[i]=arr[left];
			arr[left]=temp;
			i=left;
		}else{
			temp=arr[i];
			arr[i]=arr[right];
			arr[right]=temp;
			i=right;
		}
		left=2*i+1;
		right=2*i+2;		
	}
	if(left==n-1 && arr[i]){
		temp=arr[i];
		arr[i]=arr[left];
		arr[left]=temp;
	}
}

void display(){
	int i;
	if(n==0){
		printf("Heap is empty");
		return;
	}else{
		for(i=0;i<n;i++){
			printf("%d\t",arr[i]);
		}
		printf("\n");
	}
}

int main(){
	int ch, num;
	n=0;
	printf("1.Insert\t2.Delete\t3.Display\t4.Exit\n");
	while(1){
		printf("\nenter choice:");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				printf("enter value:");
				scanf("%d",&num);
				insert(num);
				break;
			case 2:
				del();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			default:
				printf("Wrong Choice");
		}
	}
	return 0;
}
