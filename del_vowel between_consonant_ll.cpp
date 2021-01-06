#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	char item;
	struct node *next;
}*nw,*temp,*base,*cur;

void insert(){
	char key;
	nw=(struct node *)malloc(sizeof(struct node));
	fflush(stdin);
	printf("enter value:");
	key=getchar();
	
	nw->item=key;
	
	if(base==NULL){
		base=nw;
		printf("node inserted\n");
	}
	else{
		temp->next=nw;
		printf("node inserted\n");
	}
	
	nw->next=NULL;
	temp=nw;	
}

void display(){
	temp=base;
	while(temp!=NULL){
		printf("%c\t",temp->item);
		temp=temp->next;
	}
	printf("\n");
}

bool isvowel(char c){
	char lowercase_vowel,uppercase_vowel;
	
    lowercase_vowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    uppercase_vowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    if (lowercase_vowel || uppercase_vowel)
        return true;
    else
        return false;
}

void del(){
	temp=base;
	cur=temp;
	while(temp->next!=NULL){
		
		/*while(cur->next!=temp)
			cur=cur->next;*/
		
		//printf("hello");
		if(temp==base){
			temp=temp->next;
		}
		else{
			if(!isvowel(cur->item) && !isvowel(temp->next->item) && isvowel(temp->item) ){
				cur->next=temp->next;
				free(temp);
				temp=base;
				cur=base;
				printf("node deleted\n");
			}
			else{
				cur=temp;
				temp=temp->next;
			}
		}
	}
}

int main(){
	int ch;
	
	base=NULL;
	
	while(1){
		fflush(stdin);
		printf("1.insert\t2.delete\t3.display\t4.exit\n");
	
		printf("enter choice:");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:				
				insert();	
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
				printf("\nwrong choice\n");
				getch();
		}
	}
	return 0;
}
