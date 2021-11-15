#include <stdlib.h>
#include <stdio.h>

int theSign(long double element)
{
	if (element == 0)
	{
		return 0;
	}
	if (element > 0)
	{
		return 1;
	}
	return -1;
}

int main()
{
	long long length;
	long double element;
	int sign = 1;
	printf("This program can show the sign of the multiply of all the elements of your array.\n");
	printf("Enter the length of the array:");
	scanf("%lld", &length);
	if (length <= 0)
	{
		printf("Error. Length should be > 0.");
		exit(1);
	}
	for (int i = 0; i < length; i++)
	{
		printf("Now, enter the element of the array:");
		scanf("%lld", &element);
		sign = sign * theSign(element);
	}
	printf("The sign is: %d", sign);
	return 0;
}
