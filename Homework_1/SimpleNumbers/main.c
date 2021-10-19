#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int isTrash(const char *str)
{
	for (int i = 0; i < strlen(str) - 1; i++)
	{
		if (!isdigit(str[i]) || str[0] == '0' || i > 8)
			return 1;
	}
	return 0;
}

int main()
{
	const short MaxLenOfStr = 50;
	long long number;
	char *str = (char *) malloc(sizeof(char) * MaxLenOfStr);
	short flag;

	printf("This program can print all prime numbers that do not exceed a given number.\n");
	while(1)
	{
		printf("Enter a number:");
		fgets(str, MaxLenOfStr, stdin);
		if (isTrash(str))
		{
			printf("Error! Enter a natural number which won't cause an overflow (less than a billion).\n");
		}
		else
		{
			break;
		}
	}
	number = strtoll(str, 0 ,10);
	for (long long i = 2; i <= number; i++)
	{
		flag = 0;
		for (int j = 2; j < (long long) sqrt(i)  + 1; j++)
		{
			if (i % j == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			printf("%lld\n", i);
		}
	}
	return 0;
}