#include <stdio.h>

long int pow(long int number, unsigned int degree)
{
    if (degree == 0)
    {
        return 1;
    }
    else if (degree == 1)
    {
        return number;
    }
    else if (degree % 2 == 0)
    {
        return pow(number * number, degree / 2);
    }
    else
    {
        return pow(number * number, degree / 2) * number;
    }
}
int main()
{
    long int number;
    unsigned int degree;

    printf("This program raises to an integer power.\n");
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Enter the degree of your number: ");
    scanf("%d", &degree);

    printf("The resulting number: %d \n", pow(number, degree));
    return 0;
}
