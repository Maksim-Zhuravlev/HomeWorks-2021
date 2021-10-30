#include <stdlib.h>
#include <stdio.h>

int Div(int dividend, int divisor)
{
    int sign = 1;
    if (dividend == 0 || divisor == 0)
    {
        return 0;
    }
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
    {
        sign = -1;
    }
    if (dividend > 0)
    {
        dividend = -(dividend);
    }
    if (divisor > 0)
    {
        divisor = -(divisor);
    }
    if (dividend > divisor)
    {
        return 0;
    }
    if (dividend == divisor)
    {
        return 1 * sign;
    }
    else
    {
        for (int i = 1; i <= (int)abs(dividend / 2); i++)
        {
            if (divisor * i == dividend)
            {
                return sign * i;
            }
            if (divisor * i < dividend)
            {
                return 0;
            }
            if ((dividend - divisor * i) > divisor)
            {
                return 0;
            }
        }
    }
    return 0;
}

int main()
{
    int divisor, dividend;
    const short MaxLenOfStr = 50;
    char *str_1 = (char *)malloc(sizeof(char) * MaxLenOfStr);
    char *str_2 = (char *)malloc(sizeof(char) * MaxLenOfStr);

    printf("This program can print a result of division natural numbers using function which one don't use this operation.\n");
    printf("If result won't be integer, the program will print 0\n");
    printf("WARNING! This program does not check your input, so, please, enter only integers numbers from -2147483648 to 2147483647.\n");
    printf("Enter the dividend:");
    fgets(str_1, MaxLenOfStr, stdin);
    printf("Now, enter the divisor:");
    fgets(str_2, MaxLenOfStr, stdin);
    dividend = (int)strtol(str_1, 0, 10);
    divisor = (int)strtol(str_2, 0, 10);
    printf("The answer is:%d", Div(dividend, divisor));
    return 0;
}