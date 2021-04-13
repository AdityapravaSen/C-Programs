#include <stdio.h>
#include <stdlib.h>
struct btnode{
    int value;
    struct btnode *l;
    struct btnode *r;
}*root = NULL, *temp = NULL, *t2, *t1;

void insert();
void inorder(struct btnode *t);
void create();
void search(struct btnode *t);
void preorder(struct btnode *t);
void postorder(struct btnode *t);
struct btnode *deleteNode(struct btnode *t,int);

int flag = 1;

int main(){
    int ch,key;
    temp=NULL;
    root=NULL;
    
    printf("\nOPERATIONS ---");
    printf("\n1 - Insert an element into tree\n");
    printf("2 - Inorder Traversal\n");
    printf("3 - Preorder Traversal\n");
    printf("4 - Postorder Traversal\n");
    printf("5 - Delete Node\n");
    printf("6 - Exit\n");
    
    while(1){
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        
        switch (ch){
        	case 1:    
            	insert();
            	break;
        	case 2:    
            	inorder(root);
            	break;
        	case 3:    
            	preorder(root);
            	break;
        	case 4:    
            	postorder(root);
            	break;
            case 5:
            	printf("insert key:");
            	scanf("%d",&key);
            	
            	root=deleteNode(root,key);
            	printf("node deleted\n");
            	break;
        	case 6:    
            	exit(1);
        	default :     
            	printf("Wrong choice, Please enter correct choice  ");
            	break;    
        }
    }
    return 0;
}
/* To insert a node in the tree */
void insert(){
    create();
    
    if (root == NULL) 
        root = temp;
    else    
        search(root);    
}

/* To create a node */
void create(){
    int data;
    
    printf("Enter data of node to be inserted : ");
    scanf("%d", &data);
    
    temp = (struct btnode *)malloc(1*sizeof(struct btnode));
    temp->value = data;
    temp->l = temp->r = NULL;
}

/* Function to search the appropriate position to insert the new node */
void search(struct btnode *t){
	
    if ((temp->value > t->value) && (t->r != NULL))      /* value more than root node value insert at right */
        search(t->r);
    else if ((temp->value > t->value) && (t->r == NULL))
        t->r = temp;
    else if ((temp->value < t->value) && (t->l != NULL))    /* value less than root node value insert at left */
        search(t->l);
    else if ((temp->value < t->value) && (t->l == NULL))
        t->l = temp;
}

/* recursive function to perform inorder traversal of tree */
void inorder(struct btnode *t){
	
    if (root == NULL){
        printf("No elements in a tree to display");
        return;
    }
    if (t->l != NULL)    
        inorder(t->l);
        
    printf("%d\t", t->value);
    
    if (t->r != NULL)    
        inorder(t->r);
}

void preorder(struct btnode *t){
	
    if (root == NULL){
        printf("No elements in a tree to display");
        return;
    }
    printf("%d\t", t->value);
    
    if (t->l != NULL)    
        preorder(t->l);
    if (t->r != NULL)    
        preorder(t->r);
}

/* To find the postorder traversal */
void postorder(struct btnode *t){
    if (root == NULL){
        printf("No elements in a tree to display ");
        return;
    }
    if (t->l != NULL) 
        postorder(t->l);
    if (t->r != NULL) 
        postorder(t->r);
    printf("%d\t", t->value);
}

/* find the inorder successor */
struct btnode *minValueNode(struct btnode *node) {
  struct btnode *current = node;

  // Find the leftmost leaf
  while (current && current->l != NULL)
    current = current->l;

  return current;
}

/* deleting an element */
struct btnode *deleteNode(struct btnode *t,int key){
	
	if(t==NULL)
		return t;
	
	if(key<t->value)
		t->l=deleteNode(t->l,key);
	else if(key>t->value)
		t->r=deleteNode(t->r,key);
	
	else{
		if(t->l==NULL){
			temp=t->r;
			free(t);
			return temp;
		}
		else if(t->r==NULL){
			temp=t->l;
			free(t);
			return temp;
		}
		
		temp=minValueNode(t->r);
		
		t->value=temp->value;
		t->r=deleteNode(t->r,temp->value);
	}
	return t;
}
