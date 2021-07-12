		//queue using linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct queue{			//info
	int item;
	struct queue *next;
}*front,*rear,*temp;

int count=0;

typedef struct queue *ndptr;

void enqueue(int n);
int dequeue();
void create();

int main(){
	int ch,n;
	create();
	
	while(1){
		ch=0;
		//clrscr();
		printf("\n1.Enqueue\t\t2.Dequeue\t\t3.Display\t\t4.Exit\n");
		printf("\nenter choice:\n");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				//clrscr();
				printf("\nenter no.:\n");		//insert
				scanf("%d",&n);
				enqueue(n);
				break;
			
			case 2:
				//clrscr();						//delete
				n=dequeue();
				printf("\ndeleted no.-> %d\n",n);
				break;
				
			case 3:								//display
				//clrscr();
				printf("\nQueue is:\n");
				
				if(front==NULL)
					printf("\nQueue is empty\n");
				
				for(temp=front;temp!=NULL;temp=temp->next){
					printf("%d\t",temp->item);
				}
				break;
			
			case 4:								//exit
				exit(1);
				break;
				
			default:
				printf("\nwrong input\n");
		}
	}
	
	fflush(stdin);
	getch();
	return 0;
}

//functions

void create(){		//initialize front and rear
	front=rear=NULL;
}

void enqueue(int n){	//inserting element
	ndptr nw;
	
	nw=(ndptr)malloc(sizeof(struct queue));
	nw->item=n;
	nw->next=NULL;
	
	if(rear==NULL){
		front=nw;
		rear=nw;
	}
	else{
		rear->next=nw;
		rear=nw;
	}
}

int dequeue(){			//deleting element
	ndptr nw;
	int n;
	
	if(front==NULL){
		printf("\nempty queue\n");
	}
	else{
		n=front->item;
		nw=front;
		front=front->next;
		free(nw);
	}
	
	return n;
}
