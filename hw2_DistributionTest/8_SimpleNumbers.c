#include <stdio.h>
#include <math.h>

int main()
{
	int n, f;
	printf("Enter a number:");
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		f = 0;
		for (int j = 2; j < (int)sqrt(i) + 1; j++)
		{
			if (i % j == 0)
			{
				f = 1;
				break;
			}
		}
		if (f == 0)
		{
			printf("%d ", i);
		}
	}
	return 0;
}