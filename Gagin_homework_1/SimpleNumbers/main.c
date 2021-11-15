#include <stdio.h>
#include <math.h>

int main()
{
	long long number;
	short flag;
	printf("This program can print all prime numbers that do not exceed a given number.\n");
	printf("Enter a number:");
	scanf("%lld", &number);
	for (long long i = 2; i <= number; i++)
	{
		flag = 0;
		for (int j = 2; j < (long long) sqrt(i)  + 1; j++)
		{
			if (i % j == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			printf("%lld\n", i);
		}
	}
	return 0;
}