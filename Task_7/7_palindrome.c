#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int main()
{
	int len;
	char myString[MAX_LEN];
	printf("Enter the string: ");
	fgets(myString, MAX_LEN, stdin);
	len = strlen(myString) - 1;
	int left = 0, right = len - 1, i = 0, res = 1;
	for (i; left + i < right - i; i++)
	{
		while (myString[left + i] == ' ')
		{
			left++;
		}
		while (myString[right - i] == ' ')
		{
			right--;
		}
		if (left + i < right - i)
		{
			if (myString[left + i] != myString[right - i] && myString[left + i] - 'A' != myString[right - i] - 'a' && myString[left + i] - 'a' != myString[right - i] - 'A')
			{
				res = 0;
				i = len;
			}
		}
	}
	if (res == 1)
	{
		printf("The string is a palindrome.");
	}
	else
	{
		printf("The string is not a palindrome.");
	}
	return 0;
}