// Arian Bagheri Nezhad
// 21. Б16 мм
//HomeWork 2.1

#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 5
#define MAX_STR 100

long long int power_1 (double number, int pow); // Task 5.1) In any way
double power_2 (double number, int pow); // Task 5.2) Effectively
double power_3 (double number, int pow); // Task 5.3) Recursively
int power_4 (int number, int pow); // Task 5.4) System call
long long int multi (int array[]); // Task 6) Array
void str (char string[]); // Task 7
void prime (long long int number); // Task 8
long long int fibo (int number); // Task 10

int main ()
{
    // Task 5
    printf("\ntask 5\nWrite a program that raises the ");
    printf("number a to the integer power n:\n");

    double number_a;
    int power;

    printf("Enter an positive integer: ");
    scanf("%lf", &number_a);
    printf("Enter an positive integer power: ");
    scanf("%d", &power);

    // 5.1) In any way
    printf("\n5.1) In any way: %lld\n", power_1 (number_a, power));

    // 5.2) Effectively
    printf("5.2) Effectively: %.0lf\n", power_2 (number_a, power));

    // 5.3) Recursively
    printf("5.3) Recursively: %.0lf\n", power_3 (number_a, power));

    // 5.4)
    printf("5.4) system call: %.0lf\n", power_4 (number_a, power));


    //Task 6
    printf("\n\nTask 6\nThis is a program that determines the sign (+ / - / 0) of ");
    printf("the product of all elements of an array of integers.\n");
    printf("Enter an array of five integers:\n");

    int array[MAX_STR];
    long long int result = multi (array);;
    
    if (result > 0)
    {
        printf("Is the product of multiplication: %lld\n", result);
        printf("So the sign is: \"+\"\n\n");
    }
    else if (result < 0)
    {
        printf("Is the product of multiplication: %lld\n", result);
        printf("So the sign is: \"-\"\n\n");
    }
    else
    {
        printf("Is the product of multiplication: %lld\n", result);
        printf("So the sign is: \"0\"\n\n");
    }
    

    // Task 7
    printf("Task 7\nThis is the program that defines whether a string is a palindrome:\n");
    printf("a word or text that is equally readable in both directions.\n");

    char string[100];

    printf("enter a string: ");
    gets(string);
    gets(string);

    str (string);

    printf("\n");

    // Task 8
    long long int number_b;
    printf("Task 8\nPlease Enter a positive integer larger one. This program displays prime numbers\n");
    printf("up to the number entered on the screen.\n");
    printf("Please Enter a positive integer larger one: ");
    scanf("%lld", &number_b);

    prime (number_b);

    // Task 10
    int number_c;

    printf("\n\nTask 10\nFibonacci numbers are defined as follows\n");
    printf("Fk = Fk-1 + Fk-2, for k > 2, F1 = 1, F2 =2.\n");
    printf("This program, which for a given n ≥ 1 prints Fn,\n");
    printf("Enter n: ");
    scanf("%d", &number_c);
    printf("Fn is: %lld\n\n\n", fibo (number_c));

    printf("THe end of the program!\n\n");

    return 0;
}

long long int power_1 (double number, int power)
{
    double method_1 = 1;

    for (int i = 0; i < power; i++)
    {
        method_1 = method_1 * number;
    }

    return method_1;
}

double power_2 (double number, int power)
{
    double method_2 = pow(number, power);
    
    return method_2;
}

double power_3 (double number, int power)
{
    if(power == 0) return 1;
    return number * pow(number, power - 1);
}

int power_4 (int number, int pow)
{
    if (pow == 0) return 1;
	if (pow == 1) return number;

	return power_4(number, pow / 2) * power_4(number, pow / 2) * power_4(number, pow % 2);
}

long long int multi (int array[])
{
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &array[i]);
    }

    long long multii = array[0];

    for (int i = 0; i < MAX - 1; i++)
    {
        multii *= array[i + 1];
    }

    return multii;
}

void str (char string[])
{
    int n = 0, m = strlen(string) - 1;

	while (m > n)
	{
		if (string[n++] != string[m--])
		{
			printf("'%s' is not a palindrome.\n", string);
			return;
		}
	}
	printf("'%s' is a palindrome.\n", string);
}

void prime (long long int number)
{
    int h;

    for (long long int i = 2; i <= number; i++)
    {
        h = 1;
        for (long long int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                h = 0;
                break;
            }
        }

        if (h == 1)
        {
            printf("%lld  ", i);
        }
    }
}

long long int fibo (int number)
{
    if (number <= 1 || number == 2)
    { 
    return number; 
    }
    
    return fibo(number-1) + fibo(number-2); 
}
