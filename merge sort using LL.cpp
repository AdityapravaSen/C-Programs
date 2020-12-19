		//merge sort using LL
#include<stdio.h>
#include<stdlib.h>

struct node{
	int item;
	struct node *next;
}*a,*b,*nw,*temp,*cur,*c;

void insertFirstList(int data){
	
	nw=(struct node *)malloc(sizeof(struct node));
	nw->item=data;
	
	if(a==NULL){
		a=nw;
		printf("node inserted\n");
	}
	else{
		temp->next=nw;
		printf("node inserted\n");
	}
	
	nw->next=NULL;
	temp=nw;
}

void insertSecondList(int data){
	
	nw=(struct node *)malloc(sizeof(struct node));
	nw->item=data;
	
	if(b==NULL){
		b=nw;
		printf("node inserted\n");
	}
	else{
		temp->next=nw;
		printf("node inserted\n");
	}
	
	nw->next=NULL;
	temp=nw;
}

void sort(struct node *base){
	temp=base;
	cur=NULL;
	
	int flag;
	
	while(temp){
		cur=temp->next;
		
		while(cur){
			
			if(temp->item>cur->item){
				flag=temp->item;
				temp->item=cur->item;
				cur->item=flag;
			}
			cur=cur->next;
		}
		temp=temp->next;
	}
}

void displayFirstList(){
	sort(a);
	temp=a;
	
	printf("sorted list 1\n");
	if(temp==NULL)
		printf("empty\n");
	else{
		while(temp){
			printf("%d\t",temp->item);
			temp=temp->next;
		}
		printf("\n");
	}
}

void displaySecondList(){
	sort(b);
	temp=b;
	
	printf("sorted list 2\n");
	if(temp==NULL)
		printf("empty\n");
	else{
		while(temp){
			printf("%d\t",temp->item);
			temp=temp->next;
		}
	}
	printf("\n");
}

void mergeSort(){
	node *nwBase=NULL;
	
	if(a==NULL){
		printf("list empty\n");
		return;
	}
	else if(b==NULL){
		printf("list empty\n");
		return;
	}
	else{
		if(a->item<b->item){
			c=a;
			a=c->next;
		}
		else{
			c=b;
			b=c->next;
		}
	}
	nwBase=c;
		
	while(a!=NULL && b!=NULL){
		if(a->item<=b->item){
			c->next=a;
			c=a;
			a=c->next;	
		}
		else{
			c->next=b;
			c=b;
			b=c->next;
		}
	}
	if(a==NULL)
		c->next=b;
	if(b==NULL)
		c->next=a;
		
	//display
	printf("final sorted list:\n");
	temp=nwBase;
	while(temp){
		printf("%d\t",temp->item);
		temp=temp->next;
	}
	printf("\n");
}

int main(){
	a=NULL;
	b=NULL;
	
	int ch,data;
	while(1){
		printf("1.insert 1st List\t2.insert 2nd List\t3.display\t4.exit\n");
		printf("enter choice:");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				printf("enter data:");
				scanf("%d",&data);
				insertFirstList(data);
				break;
			case 2:
				printf("enter data:");
				scanf("%d",&data);
				insertSecondList(data);
				break;
			case 3:
				displayFirstList();
				displaySecondList();
				mergeSort();
				break;
			case 4:
				exit(1);
			default:
				printf("\nwrong choice\n");
		}
	}
	return 0;
}














