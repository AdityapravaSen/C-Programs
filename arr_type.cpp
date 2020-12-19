		//finding array type
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int i;
    int odd = 0, even = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i = 0; i < n; i++)
    {
        if(arr[i] % 2 == 1)
            odd++;
        if(arr[i] % 2 == 0)
            even++;
    }
    if(odd == n)
        printf("odd");
    else if(even == n)
        printf("even");
    else
        printf("mixed");
    return 0;
}
