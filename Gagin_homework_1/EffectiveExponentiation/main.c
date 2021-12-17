#include <stdio.h>

int main()
{
	long long number, degree, multi, answer = 1;
	short flag = 0;
	const long long upper_bound = 9223372036854775807;
	const long long square_upper_bound = 3037000499;

	printf("This program can effectively raise to an integer power.\n");
	printf("Enter a number:");
	scanf("%lld", &number);
	printf("Enter the degree of your number:");
	scanf("%lld", &degree);
	multi = number;
	while (degree != 0)
	{
		if (degree % 2 == 1)
		{
			// Check that we have not gone beyond the limits of the long long type with the least losses.
			if (answer <= square_upper_bound && multi <= square_upper_bound)
			{
				answer *= multi;
			}
			else if (answer > square_upper_bound && multi > square_upper_bound)
			{
				flag += 1;
				break;
			}
			else if (answer <= square_upper_bound && multi >= square_upper_bound)
			{
				if (upper_bound / answer >= multi)
				{
					answer *= multi;
				}
				else
				{
					flag +=1;
					break;
				}
			}
			else
			{
				if (upper_bound / multi >= answer)
				{
					answer *= multi;
				}
				else
				{
					flag +=1;
					break;
				}
			}
		}


		if (degree / 2 == 0) // In order not to go beyond the overflow in vain.
		{
			break;
		}
		if (multi <= square_upper_bound)
		{
			multi *= multi;
		}
		else
		{
			flag += 1;
			break;
		}
		degree = degree / 2;
	}
	if (flag == 0)
	{
		printf("The answer is:%lld", answer);
	}
	else
	{
		printf("The answer was caused the overflow.\nPlease, restart the program and try again.");
	}
	return 0;
}