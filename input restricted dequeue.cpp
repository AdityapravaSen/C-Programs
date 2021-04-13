#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 10

struct dqueue
{
    int arr[MAX] ;
    int front, rear ;
} ;

void initdqueue ( struct dqueue * );
void addqatend ( struct dqueue *, int item ) ;
int delqatbeg ( struct dqueue * ) ;
int delqatend ( struct dqueue * ) ;
void display ( struct dqueue ) ;

int main( )
{
    struct dqueue dq ;
    int i, n, ch ;

    initdqueue ( &dq ) ;
    
    while(1){
    	printf("1.add element\t2.delete element from front\t3.delete element from back\n4.display\t5.exit.\n");
    	printf("enter choice:");
    	scanf("%d",&ch);
    	
    	switch(ch){
    		case 1:
    			printf("enter element:");
    			scanf("%d",&n);
    			
    			addqatend(&dq,n);
    			break;
    			
    		case 2:
    			i = delqatbeg ( &dq ) ;
    			printf ( "Item extracted = %d\n", i ) ;
    			break;
    		
    		case 3:
    			i = delqatend ( &dq ) ;
    			printf ( "Item extracted = %d\t", i ) ;
    			break;
    		
    		case 4:
    			display ( dq ) ;
    			break;
    		
    		case 5:
    			exit(1);
    			break;
    			
    		default:
    			printf("wrong input");		
		}
	}
}

/* initializes elements of structure */
void initdqueue ( struct dqueue *p )
{
    int i ;

    p -> front = p -> rear = -1 ;

    for ( i = 0 ; i < MAX ; i++ )
        p -> arr[i] = 0 ;
}

/* adds item at the end of dqueue */
void addqatend ( struct dqueue *p, int item )
{
    int i, k ;

    if ( p -> front == 0 && p -> rear == MAX )
    {
       printf ( "\nQueue is full.\n" ) ;
       return ;
    }

    if ( p -> rear == -1 && p -> front == -1 )
    {
        p -> rear = p -> front = 0 ;
        p -> arr[p -> rear] = item ;
        ( p -> rear )++ ;
        return ;
    }

    if ( p -> rear == MAX )
    {
        for ( i = k = p -> front - 1 ; i < p -> rear ; i++ )
        {
            k = i ;
            if ( k == MAX - 1 )
                p -> arr[k] = 0 ;
            else
                p -> arr[k] = p -> arr[i + 1] ;
        }
        ( p -> rear )-- ;
        ( p -> front )-- ;
    }
    p -> arr[p -> rear] = item ;
    ( p -> rear )++ ;
}

/* deletes item from begining of dqueue */
int delqatbeg ( struct dqueue *p )
{
    int item ;

    if ( p -> front == -1 && p -> rear == -1 )
    {
        printf ( "\nQueue is empty.\n" ) ;
        return 0 ;
    }

    item = p -> arr[p -> front] ;
    p -> arr[p -> front] = 0 ;
    ( p -> front )++ ;

    if ( p -> front == MAX )
        p -> front = -1 ;

    return item ;
}

/* deletes item from end of dqueue */
int delqatend ( struct dqueue *p )
{
    int item ;

    if ( p -> front == -1 && p -> rear == -1 )
    {
        printf ( "\nQueue is empty.\n" ) ;
        return 0 ;
    }

    ( p -> rear )-- ;
    item = p -> arr[p -> rear] ;
    p -> arr[p -> rear] = 0 ;

    if ( p -> rear == 0 )
        p -> rear = -1 ;
    return item ;
}

/* displays the queue */
void display ( struct dqueue dq )
{
    int i ;
    for ( i = 0 ; i < MAX ; i++ ){
    	if(dq.arr[i]!=0){
    		printf ( "%d\t", dq.arr[i] ) ;
		}
	}
	printf("\n");
}
