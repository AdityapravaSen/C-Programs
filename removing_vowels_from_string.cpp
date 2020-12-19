		//removing vowels from a string
#include<stdio.h>
#include<string.h>
int check_vowel(char ch)
{
	if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch =='o' || ch=='O' || ch == 'u' || ch == 'U')
      return 1;
    else
      return 0;
}
int main()
{
	char str[20],ch[20];
	int i,j=0;
	gets(str);
	for(i=0;str[i]!='\0';i++)
	{
		if(check_vowel(str[i])==0)
		{
			ch[j]=str[i];
			j++;
		}
	}
	ch[j]='\0';
	strcpy(str,ch);
	puts(str);
	return 0;
}
