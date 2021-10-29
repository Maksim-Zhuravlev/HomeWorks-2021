#include <stdio.h>

unsigned long long fib(int n)
{
    if (n <= 2)
        return 1;

    unsigned long long prev = 1, next = 1;

    for (int i = 0; i < n - 2; i++)
    {
        next = next + prev;
        prev = next - prev;
    }
    return prev;
}

int main()
{
    int n;

    printf("This program prints Fibonacci number for a giner number.\n");
    printf("Enter number n: ");
    scanf_s("%d", &n);

    while (n < 1)
    {
        printf("You can input number at least 1. Please try again.\n");

        char clean = 0;

        while (clean != '\n' && clean != EOF)
        {
            clean = getchar();
        }
        printf("Enter number: ");
        scanf_s("%d", &n);
    }
    printf("F(n) = %llu \n", fib(n));
}