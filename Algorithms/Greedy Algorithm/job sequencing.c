/*J-> 1  2  3  4  5  6  7
D-> 1  4  2  3  4  2  3
P-> 12 25 20 35 30 5 15

highest deadline=4. max 4 jobs will execute
max jobs that will execute= max(D)

1. sort using decreasing order of profit
J-> 4  5  2  3  7  1  6
D-> 3  4  4  2  3  1  2
P-> 35 30 25 20 15 12 5

2(imp). slots=1,2,3,...,max(d), then fill jobs in slot according o increasing deadline
slot=[3,4,2,5], profit= 20+35+30+25=110

eg 2--
Job ID:-    1  2  3  4  5
Deadlines:- 2  2  1  3  3
Profits:-   20 35 20 80 60

sorted-
Job ID:-    4  5  2  1  3
Deadlines:- 3  3  2  2  1
Profits:-   80 60 35 20 20

stock=[2,5,4] profit=175*/

#include<stdio.h>
#define MAX 30
struct job{
	int id;
	int deadline;
	int profit;
};

void showdata(struct job j[MAX],int lim){
	int i;
	printf("Job ID:- ");
	for(i=0;i<lim;i++){
		printf("%d ",j[i].id);
	}
	printf("\nDeadlines:- ");
	for(i=0;i<lim;i++){
		printf("%d ",j[i].deadline);
	}
	printf("\nProfits:- ");
	for(i=0;i<lim;i++){
		printf("%d ",j[i].profit);
	}
}

int findmax(struct job j[MAX],int n){
	int i,max=j[0].deadline;
	for(i=1;i<n;i++){
		if(j[i].deadline>max){
			max=j[i].deadline;
		}
	}
	return max;
}

void sort(struct job j[MAX],int n){
	int i,k;
	struct job temp;
	for(i=0;i<n;i++){
		for(k=i+1;k<n;k++){
			if(j[i].profit<j[k].profit){
				temp=j[i];
				j[i]=j[k];
				j[k]=temp;
			}
		}
	}
}

int main(){
	int i,lim,k;
	int slot[MAX];
	int max_deadline,max_profit=0;
	
	struct job j[MAX],temp;
	
	printf("enter no. of jobs:");
	scanf("%d",&lim);
	
	for(i=0;i<lim;i++){
		printf("enter job id: ");
		scanf("%d",&j[i].id);
		printf("enter deadline: ");
		scanf("%d",&j[i].deadline);
		printf("enter profit: ");
		scanf("%d",&j[i].profit);
		printf("\n");
	}
	
	showdata(j,lim);
	sort(j,lim);
	max_deadline=findmax(j,lim);
	
	for(i=0;i<max_deadline;i++){
		for(k=i+1;k<max_deadline;k++){
			if(j[i].deadline>j[k].deadline){
				temp=j[i];
				j[i]=j[k];
				j[k]=temp;
			}
		}
	}
	for(i=0;i<max_deadline;i++){
		slot[i]=j[i].id;
		max_profit+=j[i].profit;
	}
	
	printf("\n\nJob Ids- ");
	for(i=0;i<max_deadline;i++){
		printf("%d ",slot[i]);
	}
	printf("\nMax Profit: %d",max_profit);
	
	fflush(stdin);
	return 0;
}
