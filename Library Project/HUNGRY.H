  /*VALIDATION FILE*/
  void valid1(char *s)                  //This function will squeez the extra
  {                                     //blank spaces to one blank space.
       char temp[20];
       int i,j=1,k=0,f;
       for(i=0;s[i]!='\0';i++)
       {
	  f=1;
	  if(s[i]==' ')
	  {
	      if(j>=2)
		 continue;
	      else
	      {
		 temp[k++]=s[i];
		 j++;f=0;
	      }
	  }
	  if(f==1)
	  {
		 temp[k++]=s[i];
		 j=1;
	  }
       }
       temp[k++]='\0';
       strcpy(s,temp);
       return;
    }
/*===================================================================*/
  void valid2(char *s2)              //Works to accept only alphabates
  {                                  //Used in every type of name entry
       int i,j=0;
       char temp[20];
       for(i=0;s2[i]!='\0';i++,j++)
       {
	   if((s2[i]>='!')&&(s2[i]<='@')||(s2[i]>='[')&&(s2[i]<='`')||
	   (s2[i]>='{')&&(s2[i]<='~'))
	   {
		--j;
		continue;
	   }
	   else
	   temp[j]=s2[i];
       }
       temp[j]='\0';
       strcpy(s2,temp);
       return;
  }
/*===================================================================*/
  void valid3(char *s3)            //Works to accepts only numeric,alphabets,
  {                                //dots,frontslash and comma,used for road
       int i,j=0;                  //name in address
       char temp[20];                 //example, 6/1A, R.N.MUKHERJI RD.
       for(i=0;s3[i]!='\0';i++,j++)
       {

	      if((s3[i]>='!')&&(s3[i]<='+')||(s3[i]=='-')||
	      (s3[i]>=':')&&(s3[i]<='@')||(s3[i]>='[')&&(s3[i]<='`')||
	      (s3[i]>='{')&&(s3[i]<='~'))
	      {
		--j;
		continue;
	      }
	      else
	      temp[j]=s3[i];
       }
       temp[j]='\0';
       strcpy(s3,temp);
       return;
}
/*===================================================================*/
  void valid4(char *s4)            //Works to convert lower case to
  {                                // upper case.
   int length, i;                  //Used in every alphabetical entry.
   length = strlen(s4);
   for (i=0; i<length; i++)
   {
      s4[i] = toupper(s4[i]);
   }
   return;
  }
/*===================================================================*/
   void valid5(char *s5)           //Works to accepts only numeric characters
  {                                //others will be excluded.
       int i,j=0;                  // Used in pin code entry.
       char temp[10];
       for(i=0;s5[i]!='\0';i++,j++)
       {
	   if((s5[i]==' ')||(s5[i]>='!')&&(s5[i]<='/')||(s5[i]>=':')&&
							 (s5[i]<='~'))
	   {
		--j;
		continue;
	   }
	   else
	   temp[j]=s5[i];
       }
       temp[j]='\0';
       strcpy(s5,temp);
       return;
  }
/*=============================THE END===============================*/


