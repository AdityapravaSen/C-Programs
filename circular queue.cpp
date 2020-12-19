#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct que{
	int front,rear;
	char item[5];
};

int flag,flag1,fl;

int main(){
	static int ch;
	char take;
	struct que q;
	
	void insert(struct que *, char);
	char extract(struct que *);
	void display(struct que *);
	
	q.rear=-1;
	q.front=0;
	fl=flag=flag1=0;
	
	while(1){
		
		printf("\n1.insert\t\t2.extract\t\t3.display\t\t4.exit\n");
		scanf("%d",&ch);
		fflush(stdin);
		
		switch(ch){
			
			case 1:
				printf("\nenter charecter\n");
				scanf("%c",&take);
				
				insert(&q,take);
				
				break;
			
			case 2:
				take=extract(&q);
				
				printf("\nresult: %c",take);
				getch();
				
				break;
			
			case 3:
				display(&q);
				
				break;
				
			case 4:
				exit(1);
				
				break;
				
			default:
				printf("\nWrong choice\n");
		}
	}
	
	getch();
	return 0;
}

void insert(struct que *k,char tak){
	
	if(k->rear==4){		// *
		k->rear=-1;
		flag1=1;
	}
	
	if(k->rear+1==k->front && flag1==1){
		printf("\nqueue full\n");
		getch();
		fl=1;
		return;		// *		
	}
	
	k->item[++k->rear]=tak;
	flag=0;
}

char extract(struct que *k){
	char tak;
	
	if(flag==1){
		printf("\nqueue is empty\n");
		getch();
		return 0;
	}
	
	if(k->rear==k->front)
		flag=1;
		
	tak=k->item[k->front++];
	
	if(k->front>4)
		k->front=0;
		
	return tak;
}

void display(struct que *k){
	int i;
	
	for(i=k->front;i!=k->rear+1;i++){
		
		if(i>4)
			i=0;
		
		printf("\n%c ",k->item[i]);
	}
	
	getch();
}
