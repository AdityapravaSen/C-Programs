// c program to find Largest palindrome in an array

#include<stdio.h>

int check_palindrome(int n)
{
    int div = 1;
    while (n / div >= 10)
        div *= 10;

    while (n != 0)
    {
        int first = n / div;
        int last = n % 10;

        // If first and last digits are not same then return false
        if (first != last)
            return -1;

        // Removing the leading and trailing digits from the number
        n = (n % div) / 10;

        // Reducing divisor by a factor of 2 as 2 digits are dropped
        div = div / 100;
    }
    return 1;
}
int large_palindrome(int A[], int n)
{

    // Sort the array
    for(int i=0; i<=n; i++)
    {
        for(int j=i; j<= n; j++)
        {
            if(A[i] >A [j])
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        printf("%d", A[i]);
    }

    for(int i=n–1;i>=0;--i)
    {
        if (check_palindrome(A[i]) == 1)
            return A[i];
    }
    return -1;
}
int main()
{
    int a[15], n, i;
    printf(“Enter the number of entries: \n”);
    scanf(“%d”, &n);
    printf(“Enter the elements: \n”);
    for(i=0; i<n; i++)
        scanf(“%d”, &a[i]);
    printf(“\n Largest Palindrome: %d”, large_palindrome(a, n));
    return 0;
}

