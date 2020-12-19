		//Circular Linked List
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int item;
	struct node *next;
} *nw, *temp, *base, *cur;

int main(){
	static int ch, no, fl;
	
	void insert(void);
	void del(void);
	
	base=NULL;
	
	while(1){
		printf("\n1.insert\t\t2.delete\t\t3.display\t\t4.exit\n");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				insert();
				break;
				
			case 2:
				del();
				break;
				
			case 3:
				fl=0;
				printf("\nthe list is:-\n");
				
				nw=base;
				
				while(fl<2){
					printf("\n%d\t",nw->item);
					nw=nw->next;
					
					if(nw==base){
						printf("\n");
						fl++;
					}
				}
				getch();
				break;
				
			case 4:
				exit(1);
			
			default:
				printf("\nwrong input\n");
				getch();
		}
	}
}

void insert(){										
	nw=(struct node *)malloc(sizeof(struct node));					   
	
	printf("\nenter no:\n");
	scanf("%d",&nw->item);
	
	if(base==NULL)
		base=nw;
	else
		temp->next=nw;
	
	nw->next=base;
	temp=nw;
}

void del(){
	static int i, flag;
	
	printf("\nEnter no. to be deleted\n");
	scanf("%d",&i);
	
	for(nw=base;nw->item!=i && nw->next!=base; nw=nw->next)
		cur=nw;
		
	if(nw->next==base)
		flag=1;
		
	if(nw==base){
		printf("\nthe first nde cannot be deleted\n");
		getch();
		return;
	}
	
	if(flag==1 && nw->item!=i){
		printf("\nnot in list\n");
		getch();
		return;
	}
	
	if(nw!=base && nw->item==i){
		cur->next=nw->next;
		free(nw);
		return;
	}
}

