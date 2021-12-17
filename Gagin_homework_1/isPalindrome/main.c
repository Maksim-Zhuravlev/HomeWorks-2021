#include <stdio.h>
#include <string.h>
#include <ctype.h>

void low_chars(char str[500])
{
	for (int i = 0; i < strlen(str); i++)
	{
		str[i] = tolower(str[i]);
	}
}

int main()
{
	char str[500] = "Deer Madam, Reed.";
	int str_len = 0, k = 0;
	short flag = 0;
	int new_len = 0;

	printf("This program determines whether a string is a palindrome.\n");
	printf("Our string:");
	printf("%s\n",str);
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] != ' ' && str[i] != ',' && str[i] != '.' && str[i] != '!' && str[i] != '?')
		{
			str[new_len] = str[i];
			new_len++;
		}
	}
	str[new_len] = '\n';
	low_chars(str);
	for (int i = 0; str[i] != '\n'; i++)
	{
		if (str[i] == str [new_len - k - 1])
		{
			k++;
		}
		else
		{
			flag += 1;
			break;
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
