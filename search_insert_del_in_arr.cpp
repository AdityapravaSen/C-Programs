		//insert,delete,search in array
#include <stdio.h>
void insert(int array[],int n)
{
	int position,c,value;
	printf("Enter the location where you wish to insert an element\n");
   scanf("%d", &position);
 
   printf("Enter the value to insert\n");
   scanf("%d", &value);
 
   for (c = n - 1; c >= position - 1; c--)
      array[c+1] = array[c];
 
   array[position-1] = value;
 
   printf("Resultant array is\n");
 
   for (c = 0; c <= n; c++)
      printf("%d\n", array[c]);
}
void del(int array[],int n)
{
	int position,c;
	printf("Enter the location where you wish to delete element\n");
   scanf("%d", &position);

   if (position >= n+1)
      printf("Deletion not possible.\n");
   else
   {
      for (c = position - 1; c < n - 1; c++)
         array[c] = array[c+1];

      printf("Resultant array:\n");

      for (c = 0; c < n - 1; c++)
         printf("%d\n", array[c]);
   }
}
void search(int array[],int n)
{
	int i,flag=0,key;
	printf("element you want to search\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(key=array[i])
		{
			flag++;
		}
	}
	if(flag==0)
		printf("element no found\n");
	else
		printf("element present %d times",flag);
}
int main()
{
   int array[100],n,ch,c;
   printf("Enter limit\n");
   scanf("%d", &n);
   printf("Enter elements\n");
   for (c = 0; c < n; c++)
    	scanf("%d", &array[c]);
    printf("1.insert element\n2.delete element\n3.search element\n");
    scanf("%d",&ch);
    switch(ch)
    {
    	case 1:
    		insert(array,n);
    		break;
    	case 2:
    		del(array,n);
    		break;
    	case 3:
    		search(array,n);
    		break;
    	default:
    		printf("wrong choice\n");
	}
   
   return 0;
}

