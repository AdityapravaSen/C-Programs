#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
	int item;
	struct node *prev,*next;
}*base,*temp,*nw,*cur;

//creation
void insert(){	
	int x,i;
	char ab;
	
	nw=(struct node *)malloc(sizeof(struct node));
	printf("enter data:\n");
	scanf("%d",&nw->item);
	
	if(base==NULL){
		base=nw;
		base->prev=base->next=NULL;
	}
	else{
		printf("enter key:\n");
		scanf("%d",&x);
		
		fflush(stdin);
		
		printf("Before or After(b/a)?\n");
		scanf("%c",&ab);
		
		cur=base;
		//printf("%d",base);
		
		while(cur->item!=x){
			cur=cur->next;
		}
		
		//printf("%d",cur->item);
		
		if(cur==NULL){
			printf("\ncan't insert\n");
			return;
		}
		
		if(ab=='b'||ab=='B'){
			
			if(cur==base){
				nw->next=base;
				nw->prev=base->prev;
				base->prev=nw;
				base=nw;
			}
			else{
				nw->next=cur;
				nw->prev=cur->prev;
				cur->prev->next=nw;
				cur->prev=nw;
			}
			printf("\nnode inserted\n");
		}
		else if(ab=='a'||ab=='A'){
			//printf("\n%d",cur->item);
			
			nw->prev=cur;
			nw->next=cur->next;
			if(cur->next!=NULL)
				cur->next->prev=nw;
			cur->next=nw;
			
			//printf("\n%u\t%u",cur->next,nw->prev);
			
			printf("\nnode inserted\n");
		}
	}
}

void deleteFirstNode(){
	
	if(base==NULL){
		printf("\noverflow\n");
	}
	else if(base->next==NULL){
		base=NULL;
		free(base);
		
		printf("\nnode deleted\n");
	}
	else{
		temp=base;
		
		base=base->next;
		base->prev=NULL;
		free(temp);
		printf("\nnode deleted\n");
	}
}

void deleteLastNode(){
	if(base==NULL){
		printf("\nunderflow\n");
	}
	else if(base->next==NULL){
		base=NULL;
		free(base);
		
		printf("\nnode deleted\n");
	}
	else{
		temp=base;
		
		if(temp->next!=NULL){
			temp=temp->next;
		}
		temp->prev->next=NULL;
		free(temp);
		printf("\nnode deleted\n");
	}
}

void display(){
	temp=cur=base;
	while(temp){
		printf("%d\t",temp->item);
		temp=temp->next;
	}
	printf("\n");
	
	/*while(cur->next){
		cur=cur->next;
	}
	
	while(cur){
		printf("%d\t",cur->item);
		cur=cur->prev;
	}*/
}

void deleteAfterNode(){
	int key;
	printf("enter key\n");
	scanf("%d",&key);
	
	temp=base;
	while(temp->item!=key){
		temp=temp->next;
	}
	if(temp->next==NULL){
		printf("\ncant delete\n");
	}
	else if(temp->next->next==NULL){
		temp->next=NULL;
		printf("node deleted\n");
	}
	else{
		cur=temp->next;
		temp->next=cur->next;
		cur->next->prev=temp;
		free(cur);
		
		printf("node deleted\n");
	}
}

void deleteBeforeNode(){
	int key;
	printf("enter key\n");
	scanf("%d",&key);
	
	temp=base;
	while(temp->item!=key){
		temp=temp->next;
	}
	
	if(temp->prev==NULL){
		printf("\ncant delete\n");
	}
	else{
		cur=temp->prev;
		temp->prev=cur->prev;
		cur->prev->next=temp;
		free(cur);
		
		printf("node deleted\n");
	}
}




int main(){
	int ch;
	base=NULL;
	
	while(1){
		fflush(stdin);
		ch=0;
		
		printf("1.insert\t2.delete first node\t3.delete last node\t4.delete after key\n");
		printf("5.delete before key\t6.display\t7.exit\n");
		printf("enter choice:\n");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				insert();
				break;
			case 2:
				deleteFirstNode();
				break;
			case 3:
				deleteLastNode();
				break;
			case 4:
				deleteAfterNode();
				break;
			case 5:
				deleteBeforeNode();
				break;
			case 6:
				display();
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
