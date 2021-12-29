#include <stdio.h>
#include <stdlib.h>

int main(){
    long int a = 1, b = 2, t, num;

    scanf("%d", &num);

    if ( num == 1)
    {
        printf("1");
    }

    if (num == 2)
    {
        printf("2");
    }

    if (num > 2)
    {
        for (int i = 2; i < num; i++)
        {
            t = a + b;
            a = b;
            b = t;
        }

    printf("%d", b);
}

return 0;
}
