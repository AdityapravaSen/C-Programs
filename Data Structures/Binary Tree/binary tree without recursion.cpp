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

main(){
	int no;
    void insert(void);
    void preorder(void);
    void del(int);


    //clrscr();
    fflush(stdin);

    base=NULL;

    insert();
    //clrscr();
    
	fflush(stdin);

    printf("\n preorder \n");
    preorder();

    printf("\n data to be deleted :");
    scanf("%d",&no);
    del(no);

    printf("\n preorder \n");
    preorder();

    getch();
}

void insert(void){
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

 void preorder(void)
  {
   bt *stk[20];
   int i=0;
   temp=base;

   while(i>=0)
    {
     while(temp)
      {
       stk[i++]=temp;
       printf("%d,",temp->root);
       temp=temp->lc;
      }
     temp=stk[--i];
     temp=temp->rc;
    }
   return;
   }

 void del(int no)
  {
   bt *x,*parant;
   parant=x=NULL;

   temp=base;
   while(temp)
    {
     if(temp->root==no)
      {
       x=temp;
       break;
      }
     if(no>temp->root)
      {
       parant=temp;
       temp=temp->rc;
      }
     else
       {
	parant=temp;
	temp=temp->lc;
      }
    }
   if(temp->root!=no)
   {
    printf("\n data to be deleted not found ");
     getch();
     return;
    }

  if(x->lc!=NULL&&x->rc!=NULL)
   {
    parant=x;
    temp=x->rc;

    while(temp->lc!=NULL)
     {
      parant=temp;
      temp=temp->lc;
     }
    x->root=temp->root;
    x=temp;
   }

  if(x->lc==NULL&&x->rc==NULL)
   {
    if(parant->lc==x)
     parant->lc=NULL;
    else
     parant->rc=NULL;
    free(x);
    return;
   }

 if(x->lc==NULL&&x->rc!=NULL)
  {
   if(parant->lc==x)
    parant->lc=x->rc;
   else
    parant->rc=x->rc;

   free(x);
   return;
  }

 if(x->lc!=NULL&&x->rc==NULL)
  {
   if(parant->lc==x)
    parant->lc=x->lc;
   else
    parant->rc=x->lc;

   free(x);
   return;
  }
 }







