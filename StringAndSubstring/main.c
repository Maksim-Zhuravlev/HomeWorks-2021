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
		if (isdigit(str[i]))
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
	char *substr = (char *) malloc(sizeof(char) * MaxLenOfStr);
	int counter = 0;

	printf("This program can find the number of occurrences of S_1 in S as substrings.\n");
	while(1)
	{
		printf("Enter the string which contains only english letters, numbers, next symbols: '' !'?,.\" '' and whitespace\n");
		printf("(remember, that len of string should be greater than len of substring):");
		fgets(str, MaxLenOfStr, stdin);
		printf("Now, enter the substring:");
		fgets(substr, MaxLenOfStr, stdin);

		if (isTrashStr(str) || isTrashStr(substr) || strlen(str) < strlen(substr))
		{
			printf("Error!\n");
		}
		else
		{
			break;
		}
	}
	for (int i = 0; i < strlen(str) - strlen(substr) + 1; i++)
	{
		short flag = 0;
		int k = 0;
		for (int j = 0; j < strlen(substr) - 1; j++)
		{
			if (str[i + k] != substr[j])
			{
				flag = 1;
				break;
			}
		k += 1;
		}
		if (flag == 0)
		{
			counter += 1;
		}
	}
	printf("The answer is:%d", counter);
	return 0;
}
