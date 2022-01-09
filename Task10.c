#include <stdio.h>
#define N 9

int main() 
{
        printf("%d ", fibonacci(N));
}

int fibonacci(int n)  // рекурсивная функция
{
    if (n == 1 || n == 2)
        return 1; // первые 2 числа равны 1
    return fibonacci(n - 1) + fibonacci(n - 2); // складываем предыдущие 2 числа
}