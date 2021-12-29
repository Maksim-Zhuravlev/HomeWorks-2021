#include <stdio.h>
#include <stdlib.h>

int my_div(int divisor, int divident){
    int mul = 1;

    if (divisor < 0)
    {
        mul *= -1;
        divisor = -divisor;
    }

    if (divident < 0)
    {
        mul *= -1;
        divident = -divident;
    }

    int left = divident;
    int res = 0;

    while(left >= divisor){
        int multi = 1;
        while(divisor * multi <= (left >> 1) )
        {
            multi = multi<<1;
        }

        res += multi;
        left -= divisor*multi;
     }

     return res*mul;
}


int main()
{
    int x, y;
    scanf("%d %d", &x, &y);

    printf("%d", my_div(y, x));
    return 0;
}
