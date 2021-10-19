#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isNotDouble(char *str)
{
	int integer_len = 0, after_integer_len = 0;
	short point_counter = 0;
	int i = 0;

	if (str[0] == '-')
	{
		i = 1;
	}
	for (i = i; i < strlen(str) - 1; i++)
	{
		if (point_counter == 0 && isdigit(str[i]))
		{
			integer_len += 1;
		}
		if (point_counter == 1 && isdigit(str[i]))
		{
			after_integer_len += 1;
		}
		if ((str[i] == '.' || str[i] == ',') && point_counter == 0 && i != strlen(str) - 2 && i != 0)
		{
			str[i] = '.';
			point_counter += 1;
		}
		else
		{
			if (!isdigit(str[i])  || integer_len > 8 || after_integer_len > 6)
			{
				return 1;
			}
		}
	}
	return 0;
}

int isNotNatural(const char *str)
{
	for (int i = 0; i < strlen(str) - 1 ; i++)
	{
		if (!isdigit(str[i]) || i > 8)
		{
			return 1;
		}
	}
	return 0;
}

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
	const short MaxLenOfStr = 100;
	char *str = (char *) malloc(sizeof(char) * MaxLenOfStr);
	long long length;
	long double element;
	int sign = 1;

	printf("This program can show the sign of the multiply of all the elements of your array.\n");
	while(1)
	{
		printf("Enter the length of the array:");
		fgets(str, MaxLenOfStr, stdin);
		if (isNotNatural(str) || strtod(str, 0) == 0)
		{
			printf("Error! Enter a natural number which won't cause an overflow (without any symbols).\n");
		}
		else
		{
			break;
		}
	}
	length = strtoll(str, 0, 10);
	for (int i = 0; i < length; i++)
	{
		while(1)
		{
			printf("Now, enter the element of the array:");
			fgets(str, MaxLenOfStr, stdin);
			if (isNotDouble(str))
			{
				printf("Error! Enter a double number which won't cause an overflow (less than a billion and\n");
				printf("no more than 6 digits after the decimal point.\n");
			}
			else
			{
				element = strtold(str, 0);
				sign = sign * theSign(element);
				break;
			}
		}
	}
	printf("The sign is: %d", sign);
	return 0;
}
