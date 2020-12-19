#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int item;
	struct node *next;
}*nw,*temp,*base,*store,*del;

//insertion
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

//base node deletion
void deleteBaseNode(){
	
	store=base->next;
	del=base;
	
	printf("\n base node deleted\n");
	
	free(del);
	
	base=store;
	base->next=store->next;
}

//last node deletion
void deleteLastNode(){
	
	if(base==NULL)
		printf("\nempty List\n");
	else{
		
		store=del=base;
		
		while(del->next!=NULL){
			store=del;
			del=del->next;
		}
		
		if(del==base)
			base=NULL;
		else
			store->next=NULL;
		
		printf("\nlast node deleted\n");
		
		free(del);
	}
}

void search(int num){
	int i,flag=0;
	
	temp=base;
	
	if(temp==NULL)
		printf("\nempty list\n");
	else{
		while(temp!=NULL){
			
			if(temp->item==num){
				printf("\nelement found at %d\n",i+1);
				flag=0;
				break;
			}
			else{
				flag=1;
			}
			
			i++;
			temp=temp->next;
			
		}
		
		if(flag==1)
			printf("\nitem not found\n");
			
	}	
}

void deleteBeforeKey(int num){
	temp=del=store=base;
	
	while((temp->item!=num) && (temp->next!=NULL)){	
		temp=temp->next;
	}
	
	while(del->next!=temp){
		del=del->next;
	}
	
	while(store->next!=del){
		store=store->next;
	}
	
	store->next=temp;
	
	printf("\nitem deleted is %d\n",del->item);
	
	free(del);
}

void deleteAfterKey(int num){
	temp=del=store=base;
	
	while((temp->item!=num) && (temp->next!=NULL)){	
		temp=temp->next;
	}
	
	del=temp->next;
	store=del->next;
	
	temp->next=store;
	
	printf("\nitem deleted is %d\n",del->item);
	
	free(del);
}

void display(){
	temp=base;
	
	while(temp){
		printf("%d\t",temp->item);
		temp=temp->next;
	}
}

int main(){
	int num,ch;
	
	base=NULL;
	
	while(1){
		fflush(stdin);
		printf("\n1.insert\t2.delete base node\t3.delete last node\n4.search for element in the node\t5.delete node before key\t6.delete node after key\n7.display\t8.exit\n");
	
		printf("\nenter choice:\n");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				printf("\nenter value:");
				scanf("%d",&num);
				
				insert(num);
				
				break;
			case 2:
				deleteBaseNode();
				
				break;
			case 3:
				deleteLastNode();
				
				break;
			case 4:
				printf("\nenter element to search:\n");
				scanf("%d",&num);
				
				search(num);
				
				break;	
			case 5:
				printf("\nenter key:\n");
				scanf("%d",&num);
				
				deleteBeforeKey(num);
				
				break;
			case 6:
				printf("\nenter key:\n");
				scanf("%d",&num);
				
				deleteAfterKey(num);
				
				break;
			case 7:
				display();
				
				break;
			case 8:
				exit(1);
			default:
				printf("wrong choice");
				getch();
		}
	}
	return 0;
}
