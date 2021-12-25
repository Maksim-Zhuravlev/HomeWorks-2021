#include <stdio.h>

int div(int dividend, int divisor)
{
    int signRes = 0, res = 0, divisorEven = 1, d;
    signRes = (dividend >> 31) ^ (divisor >> 31);
    if (dividend < 0)
    {
        if ((dividend << 1) == 0)
        {
            dividend = dividend >> 1; //if dividend = INT_MIN_VALUE, then divide the dividend by 2
            if ((divisor << 31) == 0) //if the divisor is even, then divide the divisor by 2
            {
                divisor = divisor >> 1;
            }
            else
            {
                divisorEven = 2;
            }
        }
        dividend = ~dividend + 1;
    }
    if (divisor < 0)
    {
        if ((divisor << 1) == 0) //if the divisor = INT_MIN_VALUE, then the dividend is not = INT_MIN_VALUE, so the result will be 0
        {
            divisor = 0;
        }
        divisor = ~divisor + 1;
    }
    d = divisor;
    while ((divisor << 1) > 0)
    {
        divisor = divisor << 1;
    }
    while ((d >> 1) != divisor)
    {
        res *= 2;
        if (dividend >= divisor)
        {
            dividend -= divisor;
            res += 1;
        }
        divisor = divisor >> 1;
    }
    if (dividend != 0) //remainder not = 0
    {
        res = 0;
    }
    if (signRes == -1)
    {
        res *= (-1);
    }
    return res*divisorEven;
}

int main()
{
    int dividend, divisor;
    printf("Enter the dividend: ");
    scanf("%d", &dividend);
    printf("Enter the divisor: ");
    scanf("%d", &divisor);
    printf("%d / %d = %d", dividend, divisor, div(dividend, divisor));
    return 0;
}