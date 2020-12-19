#include<stdio.h>
void lowertoupper(char s[])
{
	int i=0;
	while(s[i]!='\0') 
    {
        if(s[i]>='a' && s[i]<='z')
        {
           s[i] -= 32;  
		}
        i++;
    }
	printf("In Upper Case is: "); 
    puts(s);
    printf("\n\n");
}
void uppertolower(char s[])
{
	int i=0;
	while(s[i]!='\0') 
    {
        if(s[i]>='A' && s[i]<='Z')
        {
           s[i] += 32;  
		}
        i++;
    }
	printf("In lower case is: "); 
    puts(s);
    printf("\n\n");
}
int main()
{
	char str[50];
	scanf("%s",str);
	int ch;
	//printf("1.for lower to upper \n2.for upper to lower:\n");
	//scanf("%d",&ch);
	//switch(ch)
	//{
	//	case 1:
				lowertoupper(str);
		//case 2:
				uppertolower(str);
//	}
	return 0;
}
