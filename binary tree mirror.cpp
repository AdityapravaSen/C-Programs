#include <stdio.h>
#include <stdlib.h>
struct btnode{
    int value;
    struct btnode *l;
    struct btnode *r;
}*root = NULL, *temp = NULL, *t2, *t1;

int count=0;
int externalCount=0;
int internalCount=0;

void create(){
	int data;
	
	printf("enter value:");
	scanf("%d",&data);
	
	temp=(struct btnode *)malloc(1*sizeof(btnode));
	temp->value=data;
	temp->l=temp->r=NULL;
}

void search(struct btnode *t){
	
    if ((temp->value > t->value) && (t->r != NULL))
    	search(t->r);
    else if ((temp->value > t->value) && (t->r == NULL))
        t->r = temp;
    else if ((temp->value < t->value) && (t->l != NULL))
        search(t->l);
    else if ((temp->value < t->value) && (t->l == NULL))
        t->l = temp;
}

void insert(){
	
	create();
	if(root==NULL)
		root=temp;
	else
		search(root);
}

int smallest(struct btnode *t){
	t2=t;
	
	if(t->l!=NULL){
		t2=t;
		return(smallest(t->l));
	}else{
		return(t->value);
	}
}

int largest(struct btnode *t){
    if (t->r != NULL){
        t2 = t;
        return(largest(t->r));
    }
	else
        return(t->value);
}

int heightOfTree(struct btnode *t){
	int max;
	
	if(t!=NULL){
		int left= heightOfTree(t->l);
		
		int right= heightOfTree(t->r);
		
		if(left>right){
			max=left+1;
			return max;
		}else{
			max=right+1;
			return max;
		}
	}
}

void countNodes(struct btnode *t){
	if(t!=NULL){
		countNodes(t->l);
		
		count++;
		if((t->l==NULL) && (t->r==NULL)){
			externalCount++;
		}
		
		countNodes(t->r);	
	}
}

void displayCount(){
	countNodes(root);
	
	internalCount=count-externalCount;
	printf("\nTotal Nodes:- %d\nLeaf(external) Nodes:- %d\nInternal Nodes:- %d\n",count,externalCount,internalCount);
}

void deleteTree(struct btnode *t){
	if(t){
		deleteTree(t->l);
		deleteTree(t->r);
		
		free(t);
	}
	printf("Tree deleted\n");
}

void inorder(struct btnode *t){
	if(t==NULL){
		printf("tree empty");
		return;
	}
	
	if(t->l!=NULL)
		inorder(t->l);
	
	printf("%d\t",t->value);
	
	if(t->r!=NULL)
		inorder(t->r);
}

void mirrorImage(struct btnode *t){
	if(t!=NULL){
		temp=NULL;
		
		mirrorImage(t->l);
		mirrorImage(t->r);
		
		temp=t->l;
		t->l=t->r;
		t->r=temp;
	}
}

void displayMirrorImage(){
	mirrorImage(root);
	inorder(root);
}

int main(){
	int ch,value;
	
	printf("\nOPERATIONS ---");
    printf("\n1 - Insert an element into tree\n");
    printf("2 - Display Tree\n");
    printf("3 - Find the smallest element\n");
    printf("4 - Find the largest element\n");
    printf("5 - display mirror image\n");
    printf("6 - Count Nodes\n");
    printf("7 - Count Height of tree\n");
    printf("8 - delete tree\n");
    printf("9 - Exit\n");
    
    while(1){
    	printf("\nenter choice:");
    	scanf("%d",&ch);
    	
    	switch(ch){
    		case 1:
    			insert();
    			break;
    		case 2:
    			inorder(root);
    			break;
    		case 3:
    			value=smallest(root);
    			printf("smallest element: %d\n",value);
    			break;
    		case 4:
    			value=largest(root);
    			printf("largest element: %d\n",value);
    			break;
    		case 5:
    			displayMirrorImage();
    			exit(2);
    		case 6:
    			displayCount();
    			break;
    		case 7:
    			value=heightOfTree(root);
    			printf("height of tree: %d\n",value);
    			break;
    		case 8:
    			deleteTree(root);
    			break;
    		case 9:
    			exit(1);
    		default:
    			printf("Wrong choice, Please enter correct choice  ");
            	break;
		}
	}
	return 0;
}













