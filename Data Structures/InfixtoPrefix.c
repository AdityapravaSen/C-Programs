#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int main()
{
    char arr[30], rar[30], stk1[20], stk2[20];
    int p = 0, l, flag, i = 0, j = -1, k = -1;

    fflush(stdin);

    printf("enter string:");
    gets(arr);

    while (arr[i] != '\0')
    {
        flag = 1;
        if (isalpha(arr[i]))
        {
            stk1[++j] = arr[i];
        }
        if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/')
        {
            stk2[++k] = arr[i];
        }
        if (arr[i] == '(' && j >= 0 && k >= 0)
        {
            for (; k >= 0; k--, p++)
            {
                rar[p] = stk2[k];
            }
            for (l = 0; l <= j; l++, p++)
            {
                rar[p] = stk1[l];
            }
            flag = 0;
            j = -1;
        }
        i++;
    }
    if (flag == 1 && j >= 0 && k >= 0)
    {
        for (; k >= 0; k--, p++)
        {
            rar[p] = stk2[k];
        }
        for (l = 0; l <= j; l++, p++)
        {
            rar[p] = stk1[l];
        }

        flag = 0;
        j = -1;
        i++;
    }

    if (flag == 1 && j >= 0 && k >= 0)
    {
        for (; k >= 0; k--, p++)
        {
            rar[p] = stk2[k];
        }
        for (l = 0; l <= j; l++, p++)
        {
            rar[p] = stk1[l];
        }
    }
    rar[p] = '\0';

    printf("Prefix is:\n");
    printf("%s", rar);
}
