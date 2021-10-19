#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isTrashStr(const char *str)
{

	for (int i = 0; i < strlen(str) - 1 ; i++)
	{
		int a = (int) str[i]; //ASCII number;
		if ((a >= 32 && a <= 34) || a == 39 || a == 44 || a == 46 || a == 63 || (a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		{
			continue;
		}
		return 1;
	}
	return 0;
}

int main() {
	const short MaxLenOfStr = 500;
	char *str = (char *) malloc(sizeof(char) * MaxLenOfStr);
	int str_len = 0;
	short flag = 0;

	printf("This program determines whether a string is a palindrome.\n");
	while(1)
	{
		printf("Enter the string which contains only english letters, next symbols: '' !'?,.\" '' and whitespace:");
		fgets(str, MaxLenOfStr, stdin);
		if (isTrashStr(str))
		{
			printf("Error!\n");
		}
		else
		{
			break;
		}
	}
	for (int i = 0; str[i] != '\n'; i++)
	{
		if (((int) str[i]) == 32 || ((int) str[i]) == 34 || ((int) str[i]) == 39 || ((int) str[i]) == 33 || ((int) str[i]) == 44 || ((int) str[i]) == 46 || ((int) str[i]) == 63)
		{
			for (int k = i; str[k] != '\0'; k++)
			{
				str[k] = str[k + 1];
			}
			i--;
		}
		else
		{
			str[i] = (char) toupper(str[i]);
			str_len += 1;
		}
	}
	for (int i = 0; str[i] != '\n'; i++)
	{

		if (i >= str_len - 1)
		{
			break;
		}
		else
		{
			if (str[i] == str [str_len - 1])
			{
				str_len -= 1;
				continue;
			}
			else
			{
				flag += 1;
				break;
			}
		}
	}
	if (flag == 0)
	{
		printf("String is a palindrome.");
	}
	else
	{
		printf("String is not a palindrome.");
	}
	return 0;
}
