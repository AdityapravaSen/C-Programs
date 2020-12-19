#include<stdio.h>
int leap_yr(int year)
{
	if (year % 4 == 0) 
	{
        if (year % 100 == 0) 
		{
            if (year % 400 == 0)
            	return 1;    
            else
                return 0;
        } 
		else
            return 1;
    }
	else
        return 0;
}
int main()
{
	int year,check;
	scanf("%d",&year);
	check=leap_yr(year);
	if(check==1)
		printf("Leap yr");
	else
		printf("not leap yr");
	return 0;
}
