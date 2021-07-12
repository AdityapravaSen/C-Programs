#include <stdio.h>
#include <stdlib.h>

struct Knapsack{
	int value;
	int weight;
	float ans;
	float ratio;
	
}items[100];


void S1(int size, int ch, int cap)
{

		int i,j;
		struct Knapsack temp;

		if(ch==3)
		{
			for(i=0;i<size;i++)
			{
				items[i].ratio = (float)items[i].value/items[i].weight;
			}
		
		for(i=0;i<size;i++)
		{
			for(j=i+1;j<size;j++)
			{
				if(items[i].ratio<items[j].ratio)
				{
					temp = items[i];
					items[i] = items[j];
					items[j] =temp;
				}
			}
			
		}
		
		}
		
				
		
		if(ch==1){
			for(i=0;i<size;i++){
				for(j=i+1;j<size;j++){
					if(items[i].value<items[j].value){
						temp=items[i];
						items[i]=items[j];
						items[j]=temp;
					}
				}
			}
		}else if(ch==2){
			for(i=0;i<size;i++){
				for(j=i+1;j<size;j++){
					if(items[i].weight>items[j].weight){
						temp=items[i];
						items[i]=items[j];
						items[j]=temp;
					}
				}
			}
		}

	if(ch==3)
	{
			for(i=0;i<size;i++){
				printf("%d 		%d  	%f\n",items[i].value,items[i].weight,items[i].ratio);
			}
	}
	else{
			
			for(i=0;i<size;i++){
				printf("%d %d\n",items[i].value,items[i].weight);
			}
	}	
	printf("\n\n");	
	int curr_wt = 0;
	int curr_cap = cap;
	double res=0.0;
	
	for(i=0; i<size;i++)
	{
		if(curr_wt+items[i].weight<=cap)
		{
			curr_wt+=items[i].weight;
			items[i].ans =1.0;
			res+=items[i].value;			
		}
		
		else{
			int rem = cap - curr_wt;
			items[i].ans = (float)rem/(float)items[i].weight;
			res += items[i].value * ((double)rem/(double)items[i].weight);
			
			break; 
		}
	}

	printf("\n\nNet Profit  = %f\n\n",res );
	printf("\nKnapsack vector:\n{  ");
	for (i = 0; i < size; i ++)
	{
		printf("  %f  ",items[i].ans );
	}
	printf("}");
			
}




int main()
{
	int cap,i,j;
	int size;
	printf("Enter the number of items  ");
	scanf("%d",&size);
	printf("\nEnter the maximum capacity of the Knapsack ");
	scanf("%d",&cap);
	
	printf("\nEnter the weights of the items  ");

	//Taking input for the weights
	for(i=0;i<size;i++)
	{
		scanf("%d", &items[i].weight);
	}
	
	printf("\nThe weights of the items are as follows : \n");
	for(i=0;i<size;i++)
	{
		printf("%d   ", items[i].weight);
	}
	
	printf("\nEnter the corresponding values of the items  ");
	//Taking input for the values
	for(i=0;i<size;i++)
	{
		scanf("%d", &items[i].value);				
	}
	
	
	int ch;
	do{
	
        printf("\nChoose one option from the following list ...\n");  
        printf("\n1.Strategy 1 : Maximize Profit By Value \n2.Strategy 2 : Maximize Profit By Weight \n3.Strategy 3 : Maximize Profit By Ratio \n4.Exit\n");    
        scanf("\n%d",&ch);  
        switch(ch)
		{
			case 1:
				S1(size,1,cap);
				break;
			
			case 2:
				S1(size,2,cap);
				break;
			
			case 3:
				S1(size,3,cap);
				break;
					
			case 4:
			exit(0);  
            break; 
			 
            default:  
            printf("Wrong input! /n Please enter valid choice.  ");  
				
		}
}
while(1);    


	return 0;
}
