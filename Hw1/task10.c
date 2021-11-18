#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	unsigned long int next;
	int count = 2;
	unsigned long int prev = 1;
	unsigned long int res = 1;
	printf("Enter n:");
	scanf("%d", &n);
	if (n > 1)
	{
		while (count < n)
		{
			next = prev + res;
			prev = res;
			res = next;
			count++;
		}
		printf("f(%d) = %d", n, res);
	}
	else
	{
		printf("f(%d) = %d", n, res);
	}
	return 0;
}