#include <stdlib.h>
#include <stdio.h>

int sign(int number)
{
    if (number > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int div_(int dividend, int divisor)
{
    int result = 1;
    int sign_result = sign(dividend) * sign(divisor);

    if (dividend == 0 || divisor == 0)
    {
        return 0;
    }

    unsigned int divisor_ = abs(divisor);
    unsigned int dividend_ = abs(dividend);

    while (divisor_ < dividend_)
    {
        dividend_ -= divisor_;
        result++;
    }
    if (result == INT_MIN && sign_result == 1)
    {
        return 0;
    }
    if (dividend_ == divisor_)
    {
        return result * sign_result;
    }
    else
    {
        return 0;
    }
    if (result == INT_MIN && sign_result == 1)
    {
        return 0;
    }
}

int main()
{
    int divisor, dividend;

    printf("This program prints a result of division natural numbers.\n");
    printf("Enter the dividend: ");
    scanf("%d", &dividend);
    printf("Enter the divisor: ");
    scanf("%d", &divisor);
    printf("The result is: %d\n", div_(dividend, divisor));

    return 0;
}