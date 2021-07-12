#include<stdio.h>
#include<stdlib.h>
#define MAX 100  

int n;    
int adj[MAX][MAX];          
int visited[MAX];              
int queue[MAX], front = -1,rear = -1;

void push_queue(int vertex);

void BFS(){
	int v;
	for(v=0; v<n; v++)
      visited[v] = 0;
	printf("Enter Start Vertex for BFS: \n");
	scanf("%d", &v);
	int i;
	push_queue(v);
	while(!isEmpty_queue()){ 
    	v = pop_queue( );
    	if(visited[v])              
        	continue; 
    	printf("%d ",v);
    	visited[v] = 1;
    	for(i=0; i<n; i++){
        	if(adj[v][i] == 1 && visited[i] == 0){
            push_queue(i);
        	}
    	}
	}
	printf("\n");
}

void push_queue(int vertex){
	if(rear == MAX-1)
    	printf("Queue Overflow\n");
	else{
    	if(front == -1)
        	front = 0;
    	rear = rear+1;
    	queue[rear] = vertex ;
	}
}

int isEmpty_queue(){
	if(front == -1 || front > rear)
      return 1;
	else
      return 0;
}

int pop_queue(){
	int delete_item;
	if(front == -1 || front > rear){
    	printf("Queue Underflow\n");
    	exit(1);
	}   
	delete_item = queue[front];
	front = front+1;
	return delete_item;
}

int main(){
   int i,j;
   printf("Enter number of vertices : ");
   scanf("%d",&n);
   
   printf("\nenter adjacency matrix(1-edge present 0-not present):\n");
   for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("from vertex %d to %d:",i,j);
   			scanf("%d",&adj[i][j]);
		}
	}
	BFS();
	return 0;
}
