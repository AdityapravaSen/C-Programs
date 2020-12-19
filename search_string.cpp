		//search charecter in string
#include<stdio.h>
#include<string.h>
int main()
{
	char str[20],ch;
	int i,flag=0;
	printf("enter string:\n");
	gets(str);
	printf("enter charecter:\n");
	scanf("%c",&ch);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==ch)
			flag++;
	}
	printf("letter present %d times",flag);
	return 0;
}
