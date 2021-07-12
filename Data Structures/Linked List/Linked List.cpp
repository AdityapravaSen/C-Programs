#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int item;
	struct node *next;
}*nw,*temp,*base,*take;

void insert(int num){
	nw=(struct node *)malloc(sizeof(struct node));
	nw->item=num;
	
	if(base==NULL)
		base=nw;
	else
		temp->next=nw;
	
	nw->next=NULL;
	temp=nw;	
}

void insert_at_beginning(int num){
	nw=(struct node *)malloc(sizeof(struct node));
	
	nw->item=num;
	nw->next=base;
	
	base=nw;
}

void insert_at_last(int num){
	nw=(struct node *)malloc(sizeof(struct node));
	
	temp=base;
	
	nw->item=num;
	nw->next=NULL;
	
	if(base==NULL){
		base=nw;
		return;
	}
	
	while(temp->next!=NULL){
		temp=temp->next;
	}
	
	temp->next=nw;
}

void insert_at_middle(int n,int num){
	int i;
	
	nw=(struct node *)malloc(sizeof(struct node));
	nw->item=num;
	
	temp=base;
	
	for(i=1;i<n;i++){
		temp=temp->next;
	}
	
	take=temp->next;
	temp->next=nw;
	nw->next=take;
}

void display(){
	temp=base;
	
	while(temp){
		printf("%d\t",temp->item);
		temp=temp->next;
	}
}

void node_count(){
	temp=base;
	int count=0;
	
	while(temp){
		count++;
		temp=temp->next;
	}
	
	printf("\nNo. of nodes: %d\n",count);
}

int main(){
	int num,n,ch;
	
	base=NULL;
	
	while(1){
		fflush(stdin);
		printf("\n1.insert\t2.insert at beginning\t3.insert at end\n4.insert after a given node\t5.node count\t6.Display\n7.Exit\n");
	
		printf("\nenter choice:\n");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				printf("\nenter value:");
				scanf("%d",&num);
				
				insert(num);
				
				break;
			
			case 2:
				printf("\nenter value:");
				scanf("%d",&num);
				
				insert_at_beginning(num);
				
				break;
			
			case 3:
				printf("\nenter value:");
				scanf("%d",&num);
				
				insert_at_last(num);
				
				break;
				
			case 4:
				printf("\nenter node after which you want to enter value:");
				scanf("%d",&n);
				
				printf("\nEnter Value:");
				scanf("%d",&num);
				
				insert_at_middle(n,num);
				
				break;
				
			case 6:
				display();
				
				break;
				
			case 5:
				node_count();
				
				break;
				
			case 7:
				exit(1);
			
			default:
				printf("\nwrong choice\n");
				getch();
		}
	}
	return 0;
}
