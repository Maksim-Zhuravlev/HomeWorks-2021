#include <stdio.h>

int main()
{
	long long int n, a;
	int res = 1, presenceOfZero = 1;
	printf("Enter the number of elements of the array: ");
	scanf("%lld", &n);
	if (n < 1)
	{
		printf("Invalid number.");
	}
	else
	{
		printf("Enter the elements of the array: ");
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &a);
			if (a == 0)
			{
				presenceOfZero = 0;
			}
			if (presenceOfZero && a < 0)
			{
				res *= (-1);
			}
		}
		printf("Multiplication sign = %d", presenceOfZero*res);
	}
	return 0;
}