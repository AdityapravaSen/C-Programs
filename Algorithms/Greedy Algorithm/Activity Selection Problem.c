	//activity selection problem
#include<stdio.h>
#define MAX 100

struct activity{
	int a,s,f;
};

int partition(struct activity list[MAX],int l,int h){
	//last element as pivot
	struct activity pivot=list[h],temp;
	int i=l-1,j;
	
	for(j=l;j<h;j++){
		if(list[j].f<=pivot.f){
			i++;
			temp=list[i];
			list[i]=list[j];
			list[j]=temp;
		}
	}
	
	temp=list[i+1];
	list[i+1]=list[h];
	list[h]=temp;
	
	return i+1;
}

void quicksort(struct activity list[MAX],int l, int h){
	int j;
	if(l<h){
		j=partition(list,l,h);
		quicksort(list,l,j-1);
		quicksort(list,j+1,h);
	}
}

//show the entered data
void showdata(struct activity list[MAX],int lim){
	int i;
	printf("Activity ID:- ");
	for(i=0;i<lim;i++){
		printf("%d ",list[i].a);
	}
	printf("\nStart Time:- ");
	for(i=0;i<lim;i++){
		printf("%d ",list[i].s);
	}
	printf("\nFinishing Time:- ");
	for(i=0;i<lim;i++){
		printf("%d ",list[i].f);
	}
}

int main(){
	int i,lim,A[MAX];
	struct activity list[MAX],temp;
	
	printf("enter no. of activities:");
	scanf("%d",&lim);
	
	for(i=0;i<lim;i++){
		printf("enter activity id: ");
		scanf("%d",&list[i].a);
		printf("enter start time: ");
		scanf("%d",&list[i].s);
		printf("enter finishing time: ");
		scanf("%d",&list[i].f);
		printf("\n");
	}
	
	//display data
	showdata(list,lim);
	
	//data after sorting
	quicksort(list,0,lim-1);
	printf("\n\nAfter sorting according to Finishing Time:\n");
	showdata(list,lim);
	
	//activity selection
	int n=0,m;
	A[n++]=list[0].a;
	i=0;
	for(m=1;m<lim;m++){
		if(list[m].s>=list[i].f && list[m].s<list[m].f){
			A[n++]=list[m].a;
			i=m;
		}
	}
	
	printf("\n\njob ids-\n");
	for(i=0;i<n;i++){
		printf("%d\t",A[i]);
	}

	return 0;
}
