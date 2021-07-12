#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct btree{
  struct btree *lc;
  int root;
  struct btree *rc;
};

typedef struct btree bt;
bt *base,*nw,*temp,*tem;

void insert(void);
void inorder(void);
//void del(void);

int main(){
	int no;
	fflush(stdin);

    base=NULL;

    insert();

    printf("\n inorder \n");
    inorder();

    getch();
    return 0;
}

void insert(){
   int i,n;
   printf("\n no of data :");
   scanf("%d",&n);

   for(i=0;i<n;i++){
     nw=(bt *)malloc(sizeof(bt));
     printf("\n data :");
     scanf("%d",&nw->root);

     nw->lc=nw->rc=NULL;

     if(base==NULL)
      base=nw;
      
     else{
       temp=base;

       while(temp){
	 	 tem=temp;
	 	
		 if(nw->root>=temp->root)
	   		temp=temp->rc;
	 	else
	   		temp=temp->lc;
		}
		
	 if(nw->root>=tem->root)
	 	tem->rc=nw;
	 else
	 	tem->lc=nw;
	 }
    }
    
    return;
}

void inorder(){
	bt *stk[20];
    int i=0,done=0;
    temp=base;
    
    while(!done){
    	if(temp!=NULL){
    		stk[i++]=temp;
    		temp=temp->lc;
		}
		else{
			if(i>0){
				temp=stk[--i];
				printf("%d\n",temp->root);
				temp=temp->rc;
			}
			else{
				done=1;
			}
		}
	}
}
