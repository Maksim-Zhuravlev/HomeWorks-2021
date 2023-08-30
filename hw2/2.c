#include <stdio.h>
#include<string.h>
#include<math.h>
int div(int divisor, int divident) {
    int d = 0;
    int r1, r2,t1,t2;
    r1 = abs(divisor); t1 = r1;
    r2 = abs(divident); t2 = r2;
    while (r1 >= r2) {
        r1 = r1 - r2;
        d++;
    }
    if (r1 == 0)
    {
        if ((t1 == divisor && t2 == divident) || (t1 == -divisor && t2 == -divident))
        {
            return d;
        }
        else { return -d; }
    }

    else { return 0; }
}

int main()
{
    int x, y, i;
    scanf("%d%d", &x, &y);
    i = div(x, y);
    printf("%d", i);
}