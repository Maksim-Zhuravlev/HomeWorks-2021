#include <stdio.h>

int main()
{
	int n;
	double a, res = 1;
	printf("Enter the number to be raised to the power: ");
	scanf("%lf",&a);
	printf("Enter the degree: ");
	scanf("%d",&n);
	printf("%g to the power %d = ", a, n);
	if (n < 0)
	{
		n *= (-1);
		a = 1 / a;
	}
	while (n > 0)
	{
		if (n % 2 == 1)
		{
			res *= a;
		}
		n /= 2;
		a*=a;
	}
	printf("%g", res);
	return 0;
}