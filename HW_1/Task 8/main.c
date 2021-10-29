#include <stdio.h>
#include <math.h>

int is_prime(int number)
{
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }
    if (number == 1)
    {
        return 0;
    }
    return 1;
}

int main()
{
    int x;

    printf("This program prints prime numbers that do not exceed a given number.\n");
    printf("Enter number: ");
    scanf_s("%d", &x);

    while (x < 1)
    {
        printf("You cannot input negative numbers or letters. Please try again.\n");

        char clean = 0;

        while (clean != '\n' && clean != EOF)
        {
            clean = getchar();
        }
        printf("Enter number: ");
        scanf_s("%d", &x);
    }

    printf("Prime numbers up to %d:\n", x);

    for (int i = 1; i < x; i++)
    {
        if (is_prime(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}