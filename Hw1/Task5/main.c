#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n;
    float a, x;
    x = 1.0;
    printf("Введите a\n");
    scanf("%f", &a);
    printf("Введите n\n");
    scanf("%d", &n);
    double p = log(n) / log(2);
    p += 0.5;
    int s = (int) round(p);
    int arr[s];
    for (int  i = 0; i < s; i++) {
        arr[s - i - 1] = n % 2;
        n = n / 2;
    }
    for (int i = 0; i < s - 1; i++) {
        x = pow(x * pow(a, (double) arr[i]), 2.0);
    }
    x = x * pow(a, (double) arr[s - 1]);
    int r = (int) x;
    printf("Результат: %d", r);
    return 0;
}
