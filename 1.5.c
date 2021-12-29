#include <stdio.h>
#include <stdlib.h>

int main()

{
    int a, b;
    scanf("%d %d", &a, &b);

    int t = 1;
    int a1 = a;

    while (t*2 <= b)
    {
        a1=a1*a1;
        t = t*2;
    }

    while (t<b)
    {
        a1 = a1*a;
        t++;
    }

 printf("%d", a1);

return 0;
}
