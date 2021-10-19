#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>



int isTrash(const char *str)
{
	for (int i = 0; i < strlen(str) - 1 ; i++)
	{
		if (!isdigit(str[i]) || str[0] == '0' || i > 8)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	const short MaxLenOfStr = 50;
	long long number;
	long long prev = 1, curr = 2, next = 1;
	char *str = (char *) malloc(sizeof(char) * MaxLenOfStr);
	printf("This program outputs Fibonacci number for a given natural number.\nLet's say that the first is 1, the second is 2, etc.\n");
	while(1)
	{
		printf("Enter the number:");
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
	number = strtoll(str,0,10);
	for (int i = 2; i < number; i++)
	{
		next = prev + curr;
		prev = curr;
		curr = next;
	}
	if (number == 2)
	{
		printf("2");
	}
	else
	{
		printf("%lld", next);
	}
	return 0;
}
