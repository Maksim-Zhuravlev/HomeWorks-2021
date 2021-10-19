#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isTrash (const char *str)
{
	for (int i = 0; i < strlen(str) - 1; i++)
	{
		if (!isdigit(str[i]) || str[0] == '0' || i > 8)
			return 1;
	}
	return 0;
}

int main() {
	const short MaxLenOfStr = 50;
	long long number, degree, multi, answer = 1;
	char *str_1 = (char *) malloc(sizeof(char) * MaxLenOfStr);
	char *str_2 = (char *) malloc(sizeof(char) * MaxLenOfStr);
	short flag = 0;
	const long long upper_bound = 9223372036854775807;
	const long long square_upper_bound = 3037000499;

	printf("This program can effectively raise to an integer power.\n");
	while(1)
	{
		printf("Enter a number:");
		fgets(str_1, MaxLenOfStr, stdin);
		printf("Enter the degree of your number:");
		fgets(str_2, MaxLenOfStr, stdin);

		if (isTrash(str_1) || isTrash(str_2))
		{
			printf("Error! Enter only natural numbers which won't cause an overflow (less than a billion).\n");
		}
		else
		{
			break;
		}
	}
	number = strtoll(str_1, 0 ,10);
	degree = strtoll(str_2, 0, 10);
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
