#include <stdlib.h>
#include <stdio.h>

int Div(int divisor, int divident)
{
	int sign = 1;
	if (divisor == 0 || divident == 0)
	{
		return 0;
	}
	if ((divisor > 0 && divident < 0) || (divisor < 0 && divident > 0))
	{
		sign = -1;
	}
	if (divisor > 0)
	{
	divisor = -(divisor);
	}
	if (divident > 0)
	{
		divident = -(divident);
	}
	if (divisor > divident)
	{
		return 0;
	}
	if (divisor == divident)
	{
		return 1 * sign;
	}
	else
	{
		for (int i = 1; i <= (int) abs(divisor/2); i++)
		{
			if (divident * i == divisor)
			{
				return sign * i;
			}
			if (divident * i < divisor)
			{
				return 0;
			}
			if ((divisor - divident * i) > divident)
			{
				return 0;
			}

		}

	}
	return 0;
}


int main() {
	int divisor, divident;
	const short MaxLenOfStr = 50;
	char *str_1 = (char *) malloc(sizeof(char) * MaxLenOfStr);
	char *str_2 = (char *) malloc(sizeof(char) * MaxLenOfStr);

	printf("This program can print a result of division natural numbers using function which one don't use this operation.\n");
	printf("If result won't be integer, the program will print 0\n");
	printf("WARNING! This program does not check your input, so, please, enter only integers numbers from -2147483648 to 2147483647.\n");
	printf("Enter the divisor:");
	fgets(str_1, MaxLenOfStr, stdin);
	printf("Now, enter the divident:");
	fgets(str_2, MaxLenOfStr, stdin);
	divisor = (int) strtol(str_1, 0, 10);
	divident = (int) strtol(str_2, 0, 10);
	printf("%d,%d", divisor,divident);
	printf("The answer is:%d", Div(divisor, divident));
	return 0;
}
