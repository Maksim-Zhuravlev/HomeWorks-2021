#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s1[150];
	char s2[150];
	printf("Enter s1:");
	gets(s1);
	printf("Enter s2:");
	gets(s2);
	int key, count = 0, len_s1 = (int)strlen(s1), len_s2 = (int)strlen(s2);
	for (int i = 0; i < len_s1; i++)
	{
		key = 1;
		for (int k = 0; k < len_s2; k++)
		{
			if (s1[i + k] != s2[k])
			{
				key = 0;
				break;
			}
		}
		if (key)
		{
			count += 1;
		}
	}
printf("s2 to s1 occurs %d times",count);
}