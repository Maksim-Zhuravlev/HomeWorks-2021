// Arian Bagheri Naezhad
// 21. Б.16 мм
// HomeWork 3_2

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>

#define MAX 31

int div_fun (int divisor, int divident);
int process_a (int divisor, int divident);

int main ()
{
    int n, m, result;
    char ch = 'y';

    printf("\nImplement function\n");
    printf("int div(int divisor, int divident) {\n");
    printf("return divisor / divident;\n");
    printf("}\n");
    printf(", replacing division with your own implementation without\n");
    printf("using the specified operation.\n");
    printf("If the result is not representable in int, then return 0.\n");
    printf("Hints:\n");
    printf("- INT_MIN_VALUE will be among the input values ​​for testing,\n");
    printf("- there will be all combinations of signs of the divisor and the dividend,\n");
    printf("- there are solutions that are faster and more elegant than subtraction in a loop.\n\n");

    while (ch == 'y')
    {
        printf("\nEnter n: ");
        scanf("%d", &n);
        printf("Enter m: ");
        scanf("%d", &m);

        result = 0;
        result = div_fun(n, m);

        printf("Result is: %d\n", result);

        printf("For the end, enter n, else y: ");
        ch = getch();
    }

    return 0;
}

int div_fun (int divisor, int divident)
{
    int Response = 0;
    unsigned int accum = 0, divisor_n = abs(divisor), divident_m= abs(divident);

    for (int i = MAX; i >= 0; i--)
    {
        if ((divident_m << i) > 0 && accum + (divident_m << i) <= divisor_n) {
            Response |= 1 << i;
            accum += divident_m << i;
        }
    }
    if (Response == INT_MIN && process_a(divisor, divident) == 1) {
        return 0;
    }

    return accum == divisor_n ? Response * process_a(divisor, divident) : 0;
}

int process_a (int divisor, int divident)
{
    if ((divisor < 0) ^ (divident < 0))
    {
        return -1;
    }
    else 
    {
        return 1;
    }
}