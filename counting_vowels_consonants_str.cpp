		//counting no. of vowels and consonants
#include<stdio.h>
int main()
{
	char str[20];
	int i,vowels=0,consonants=0;
	gets(str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
			vowels++;
		else
			consonants++;
	}
	printf("vowels:%d\tconsonants:%d",vowels,consonants);
	return 0;
}
