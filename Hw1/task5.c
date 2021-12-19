#include <stdio.h>
#include <stdlib.h>

long pow(int n, int deg) {

	long res = 1;

	while (deg) {
		if (deg % 2 != 0) {
			deg--;
			res *= n;
		}
		else {
			deg /= 2;
			n *= n;
		}
	}
}

int main()
{
	int n;
	int deg;
 	int ans = 1;

	printf("Enter number:");
	scanf("%d", &n);
	printf("Enter the degree:");
	scanf("%d", &deg);

	printf("Answer: %d",pow(n, deg);
	return 0;
}