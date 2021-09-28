#include <stdio.h>
#include <stdlib.h>

int Fib(int n)
{
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        return Fib(n - 2) + Fib(n - 1);
    }
}
int main()
{
    int k;
    printf("k = ");
    scanf("%d", &k);
    printf("F(k) = %d", Fib(k));
    return 0;
}
