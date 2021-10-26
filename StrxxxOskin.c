#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// int div task-2
int divT(int divisor, int divident)
{
	int result = 0;
	if (divisor < 0 && divident > 0)
	{
		int ost = divisor + divident;
		for (; ost <= 0; ost += divident)
			result--;
		return ost ? result - 1 : result;
	}
	else
	{
		for (int i = divisor - abs(divident); i >= 0; i -= abs(divident))
			result++;
		return divident > 0 ? result : -result;
	}
}

int main()
{
	int A, B;

	printf("Enter A:\n");
	scanf("%d", &A);
	printf("Enter B:\n");
	scanf("%d", &B);

	printf("\n%d", divT(A, B));

}

