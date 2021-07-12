#include<stdio.h>
#include<stdlib.h>

struct node{
	int item;
	struct node *next;
	struct node *prev;
}*base,*temp,*nw,*cur;

void insertAtBeginning(){
	//int data;
	
	nw=(struct node *)malloc(sizeof(struct node));
	
	if(nw==NULL)
		printf("\noverflow");
	else{
		printf("enter data:");
		scanf("%d",&nw->item);
		
		if(base==NULL){
			base=nw;
			nw->next=base;
			nw->prev=base;
		}
		else{
			temp=base;
			
			while(temp->next!=base)
				temp=temp->next;
				
			temp->next=nw;
			nw->prev=temp;
			base->prev=nw;
			nw->next=base;
			base=nw;
		}
		printf("node inserted\n");
	}
}

void insertAtEnd(){
	nw=(struct node *)malloc(sizeof(struct node));
	
	if(nw==NULL)
		printf("overflow\n");
	else{
		printf("enter data:");
		scanf("%d",&nw->item);
		
		if(base==NULL){
			base=nw;
			nw->next=base;
			nw->prev=base;
		}
		else{
			temp=base;
			
			while(temp->next!=base)
				temp=temp->next;
			
			temp->next=nw;
			nw->prev=temp;
			base->prev=nw;
			nw->next=base;
		}
		printf("node inserted\n");
	}
}

void deleteFirstNode(){
	if(base==NULL){
		printf("\nunderflow\n");
	}
	else if(base->next==base){
		base=NULL;
		free(base);
		printf("node deleted\n");
	}
	else{
		temp=base;
		while(temp->next!=base)
			temp=temp->next;
		
		temp->next=base->next;
		base->next->prev=temp;
		free(base);
		base=temp->next;
		
		printf("node deleted\n");
	}
}

void deleteLastNode(){
	if(base==NULL){
		printf("\nunderflow\n");
	}
	else if(base->next==base){
		base=NULL;
		free(base);
		printf("node inserted\n");
	}
	else{
		temp=base;
		
		while(temp->next!=base){
			temp=temp->next;
		}
		temp->prev->next=base;
		base->prev=temp->prev;
		free(temp);
		
		printf("node deleted\n");
	}
}

void deleteAfterNode(){
	int key;
	temp=base;
	
	printf("enter key node:");
	scanf("%d",&key);
	
	if(base==NULL){
		printf("underflow\n");
		return;
	}
	
	while(temp->item!=key){
		if(temp->next==base){
			printf("key doesn't exist\n");
			return;
		}
		
		temp=temp->next;
	}
	cur=temp->next;
	temp->next=cur->next;
	cur->next->prev=temp;
	free(cur);
	printf("node deleted\n");
	
}

void display(){
	temp=base;
	
	while(temp->next!=base){
		printf("%d\t",temp->item);
		temp=temp->next;
	}
	
	printf("%d\n",temp->item);
}

int main(){
	int ch;
	
	base=NULL;
	
	while(1){
		printf("1.insert at beginning\t2.insert at end\n3.delete at beginning\t4.delete at end\n");
		printf("5.delete after specified node\t6.display\t7.exit\n");
		printf("enter choice:");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				insertAtBeginning();
				break;
			case 2:
				insertAtEnd();
				break;
			case 3:
				deleteFirstNode();
				break;
			case 4:
				deleteLastNode();
				break;
			case 5:
				deleteAfterNode();
				break;
			case 6:
				display();
				break;
			case 7:
				exit(1);
			default:
				printf("\nwrong choice");
		}
	}
	return 0;
}












