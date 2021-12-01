#include <stdio.h>
#include <math.h>

int isPrime(long long int i)
{
	long long int c = sqrt(i), j;
	int count = 1;
	for (j = 3; j <= c; j += 2)
	{
		if (i % j == 0)
		{
			count = 0;
			j = c + 1;
		}
	}
	return count;
}

int main()
{
	long long int n, i = 3;
	int res = 1;
	printf("Enter the number: ");
	scanf("%lld", &n);
	if (n < 2)
	{
		printf("There are no prime numbers less than %lld.", n);
	}
	else
	{
		printf("Prime numbers not exceeding %lld: 2", n);
		for (i; i <= n; i+=2)
		{
			if (isPrime(i))
			{
				printf(", %lld", i);
			}
		}
		printf(".");
	}
	return 0;
}