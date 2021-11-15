#include <stdio.h>

int main()
{
	long long number;
	long long prev = 1, curr = 2, next = 1;

	printf("This program outputs Fibonacci number for a given natural number.\nLet's say that the first is 1, the second is 2, etc.\n");
	printf("Enter the number:");
	scanf("%lld", number);
	for (int i = 2; i < number; i++)
	{
		next = prev + curr;
		prev = curr;
		curr = next;
	}
	if (number == 2)
	{
		printf("2");
	}
	else
	{
		printf("%lld", next);
	}
	return 0;
}
