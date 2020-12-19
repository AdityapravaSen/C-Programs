#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	Node *next;
}*top=NULL,*p;

Node *newnode(int x)
{
	p=new Node;
	p->data=x;
	p->next=NULL;
	return p;	
}

//peeking for top
void peek(){ 
    if (top!=NULL) 
        printf("%d", top->data);
}

void push(Node *q)
{
	if(top==NULL)
		top=q;
	else
	{
		q->next=top;
		top=q;
	}
}

void pop()
{
	if(top==NULL)
		printf("empty stack\n");
	else
	{
		printf("Deleted element is %d",top->data);
		p=top;
		top=top->next;
		delete(p);
	}
}

void showstack()
{
	Node *q;
	q=top;
	if(top==NULL)
		printf("empty stack\n");
	else
	{
		while(q!=NULL)
		{
			printf("%d	",q->data);
			q=q->next;
		}
	}
}

int main()
{
	int ch,x;
	Node *nptr;
	while(1)
	{
		printf("\n\n1.push\n2.pop\n3.display\n4.exit\n5.peek");
		printf("\nchoice(1-4):-");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
					printf("\nenter data");
					scanf("%d",&x);
					nptr=newnode(x);
					push(nptr);
					break;
			case 2:
					pop();
					break;
			case 3:
					showstack();
					break;
			case 4:
					exit(0);
			case 5:
					peek();
					break;
			default:
					printf("\nwrong choice");
		}
	}
	return 0;
}
