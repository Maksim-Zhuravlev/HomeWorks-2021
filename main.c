#include <stdio.h>
#include <math.h>

#define MAXLENGTH 256

int strlength(char *string)
{
    int count = 0, i = 0;
    while (string[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}

int strcmp_strings(char *string_1, char *string_2)
{
    int i, maxlength = 0, flag = 1;
    if (strlength(string_1) > strlength(string_2))
    {
        return 1;
    }
    else if (strlength(string_1) < strlength(string_2))
    {
        return -1;
    }
    else
    {
        for (i = 0; i < strlength(string_1); i++)
        {
            if (string_1[i] != string_2[i])
            {
                if (string_1[i] > string_2[i])
                {
                    flag = 0;
                    return 1;
                }
                else
                {
                    flag = 0;
                    return -1;
                }
            }
        }
        if (flag == 1)
            return 0;
    }
}

int strcopy(char *to, char *from)
{
    int i = 0;
    while (from[i] != '\0')
    {
        to[i] = from[i];
        i++;
    }
    if (from[i] == '\0')
        to[i] = '\0';
}

int stringcat(char *to, char *from)
{
    int i, j = 0, length_1 = strlength(to), length_2 = strlength(from);
    for (i = length_1 - 1; i < (length_1 + length_2); i++)
    {
        if (j < length_2)
        {
            to[i] = from[j];
            j++;
        }
        if (i == (length_1 + length_2) - 1)
            to[i] = '\0';
    }
}

int div(int divisor, int dividend)
{
    int count = 0, divisor_2 = 0;
    if (divisor == 0)
        return -1;
    if ((divisor >= 0 && dividend >= 0) || (divisor <= 0 && dividend <= 0))
    {
        divisor = abs(divisor);
        dividend = abs(dividend);
        while (divisor_2 < dividend) {
            divisor_2 += divisor;
            count++;
        }
        if (divisor_2 == dividend)
            return count;
        else
            return 0;
    }
    if ((divisor >= 0 && dividend <= 0) || (divisor <= 0 && dividend >= 0))
    {
        divisor = abs(divisor);
        dividend = abs(dividend);
        while (divisor_2 < dividend) {
            divisor_2 += divisor;
            count++;
        }
        if (divisor_2 == dividend)
            return -count;
        else
            return 0;
    }
}

int main()
{
    int divisor, dividend;
    printf("Enter the dividend: ");
    scanf("%d", &dividend);
    printf("Enter the divisor: ");
    scanf("%d", &divisor);
    printf("%d / %d = %d\n", dividend, divisor, div(divisor, dividend));
    return 0;
}
