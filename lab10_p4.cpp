		//comparing 2 strings without strcmp()
#include<stdio.h>
char stringComp(const char* str1,const char* str2)
{
	int d,i;
	for(i=0;str1[i]==str2[i] && str1[i]!='\0' && str2[i]!='\0';i++);
	return str1[i]-str2[i];
}
int main()
{
	char a[100],b[100],d;
	printf("Enter two word: ");
	scanf("%s%s",&a,&b);
	d=stringComp(a,b);
	if(d>0)
		printf(" %s is greater than %s ",a,b);
	else if(d<0)
		printf(" %s is smaller than %s ",a,b);
	else
		printf(" %s is equal to %s ",a,b);
}

