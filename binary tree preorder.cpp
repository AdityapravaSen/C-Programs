			//preorder traversal of binary tree			
#include<stdio.h>
#include<stdlib.h>

struct binary{
	int data;
	struct binary *lt,*rt;
};

void insert(struct binary **,int);
void preorder(struct binary *);

int main(){
	struct binary *bt;
	int num,lim,i;
	
	bt=NULL;
	
	printf("\nenter limit:\n");
	scanf("%d",&lim);
	
	for(i=0;i<lim;i++){
		printf("\nenter data:");
		scanf("%d",&num);
		
		insert(&bt,num);
	}
	
	preorder(bt);
	
	return 0;
}

void insert(struct binary **t,int num){
	
	if(*t==NULL){
		*t=(struct binary*)malloc(sizeof(struct binary));
		
		(*t)->lt=NULL;
		(*t)->data=num;
		(*t)->rt=NULL;
		
		return;
	}
	else{
		
		if(num<(*t)->data)
			insert(&((*t)->lt),num);
		else
			insert(&((*t)->rt),num);
			
		return;
	}
}

void preorder(struct binary *t){
	
	if(t!=NULL){
		printf("%d\t",t->data);
		preorder(t->lt);
		preorder(t->rt);
	}
	else{
		return;
	}
	
	return;
}












