#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int main()
{
	long long int len1, len2;
	char myString1[MAX_LEN], myString2[MAX_LEN];
	printf("Enter the first string: ");
	fgets(myString1, MAX_LEN, stdin);
	printf("Enter the second string: ");
	fgets(myString2, MAX_LEN, stdin);
	len1 = strlen(myString1) - 1;
	len2 = strlen(myString2) - 1;
	int i = 0, res = 0, count = 0;
	for (i; i <= len1 - len2; i++)
	{
		if (myString1[i] == myString2[0])
		{
			count = 0;
			for (int j = 1; j < len2; j++)
			{
				if (myString1[i + j] != myString2[j])
				{
					count = 1;
					j = len2;
				}
			}
			if (count == 0)
			{
				res += 1;
			}
		}
	}
	printf("The second line enters the first as a substring %d times.", res);
	return 0;
}