#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s1[100];
	char s2[100];
	printf("Enter your phrase:");
	gets(s1);
	int is_poly = 1, len_s1 = (int)strlen(s1), len_s2 = 0;
	for (int i = 0; i < len_s1; i++)
	{
		if (s1[i] != ' ')
		{
			s2[len_s2] = s1[i];
			len_s2 += 1;
		}
	}
	for (int i = 0; i < len_s2/2; i++)
	{
		if (s2[i] != s2[len_s2-1-i] && s2[i] + 32 != s2[len_s2-1-i] && s2[i] - 32 != s2[len_s2-1-i])
		{
			is_poly = 0;
			break;
		}
	}
	if (is_poly)
	{
		printf("\nThis is a polyndrome.\n");
	}
	else
	{
		printf("\nThis is not a polyndrome.\n");
	}
	return 0;
}