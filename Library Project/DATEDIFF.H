/* CALCULATING DIFFERENCE BETWEEN RETURN & ISSUE DATE*/
int datediff(int iday,int imon,int iyear,int rday,int rmon,int ryear)
{
	int days,dm;
	days=0;
	dm=0;
	dm=daycount(imon,iyear);
	if(iday==rday && imon==rmon && iyear==ryear)
	    return(0);
	while(1)
	{
		days=days+1;
		iday+=1;
		if (iday>dm)
		{
		    imon++;
		    iday=1;
		    if(imon > 12)
		    {
			    iyear++;
			    imon=1;
		    }
		    dm=daycount(imon,iyear);
		}
		if(iday==rday && imon==rmon && iyear==ryear)
			break;
	}
	return (days);
}

int daycount(int m,int y)
{
	int dm;
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		dm=31;
	if(m==4||m==6||m==9||m==11)
		dm=30;
	if(m==2)
	{
		dm=28;
		if(y%400==0||(y%100!=0&&y%4==0))
			dm=29;
	}
	return(dm);
}
