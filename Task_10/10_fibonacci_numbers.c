#include <stdio.h>

int main()
{
	long long int n;
	printf("Enter the number of the Fibonacci number: ");
	scanf("%lld", &n);
	if (n < 1)
	{
		printf("Invalid Fibonacci number.");
	}
	else if (n > 92)
	{
		printf("Fibonacci number too large.");
	}
	else
	{
		printf("%lld Fibonacci number = ", n);
		unsigned long long int fib[3] = { 3, 1, 2 }, counter = 4;
		for (counter; counter <= n; counter++)
		{
			fib[counter % 3] = fib[(counter + 1) % 3] + fib[(counter + 2) % 3];
		}
		printf("%llu", fib[n % 3]);
	}
	return 0;
}