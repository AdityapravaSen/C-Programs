#include<stdio.h>
#include<conio.h>
#define MAX 10
int stack[MAX];
int top=-1;
int is_empty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int is_full()
{
	if(top==MAX-1)
		return 1;
	else
		return 0;
}
void push(int n)
{
	int check;
	check=is_full();
	if(check==1)
		printf("overflow\n");
	else
	{
		top++;
		stack[top]=n;
	}
}
int pop()
{
	int data,check;
	check=is_empty();
	if(check==1)
		printf("underflow\n");
	else
	{
		data=stack[top];
		top--;
	}
	return data;
}
int main()
{
	int a[10],n,i=0,data;
	printf("limit-");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	i=0;
	while(i<n)
	{
		push(a[i]);
		i++;
	}
	while(!is_empty())
	{
		data=pop();
		printf("%d	",data);
	}
	return 0;
}
