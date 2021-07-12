#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define MAX 100
float s[MAX];
int top=-1;
void push(float s[],float val);
float pop(float s[]);
float evaluatePostfix(char e[]);
int main()
{
	float val;
	char e[100];
	printf("\nEnter any postfix expression\n");
	gets(e);
	val=evaluatePostfix(e);
	printf("\nThe value of the postfix expression is %.2f",val);
	return 0;
}
float evaluatePostfix(char e[])
{
	int i=0;
	float a,b,c;
	while(e[i]!='\0')
	{
	if (isdigit(e[i]))
		push(s, (float)(e[i]-'0'));
	else
	{
		b=pop(s);
		a=pop(s);
		switch(e[i])
		{
			case '+':
				c=a+b;
				break;
			case '-':
				c=a-b;
				break;
			case '/':
				c=a/b;
				break;
			case '*':
				c=a+b;
			case '%':
				c= (int)a%(int)b;
				break;
		}
		push(s,c);
	}
	i++;
}
return(pop(s));
}
void push(float s[],float val)
{
	if (top==MAX-1)
	{
		printf("\nSTACK OVERFLOW");
	}
	else
	{
		top++;
		s[top]=val;
	}
}
float pop(float s[])
{
	float val=-1;
	if(top==-1)
		printf("\nStack underflow");
	else
	{
		val=s[top];
		top--;
	}
	return val;
}
