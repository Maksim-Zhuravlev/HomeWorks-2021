#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	const short MaxLenOfStr = 500;
	char str[MaxLenOfStr];
	char substr[MaxLenOfStr];
	int counter = 0;

	printf("This program can find the number of occurrences of S_1 in S as substrings.\n");
	printf("Enter the string which contains only english letters and numbers (<500 symbols).\n");
	scanf("%s", str);
	printf("Now, enter the substring:");
	scanf("%s", substr);
	if (strlen(str) - strlen(substr) < 0)
	{
		printf("Error. Len of str should be >= len of substr.");
		exit(0);
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
