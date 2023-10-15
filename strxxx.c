#include <stdio.h>
#define MAX_LEN 256 // максимальная длина строки
int strlen(char* a);
int strcmp(char* a, char* b);
char* strcpy(char* a, char* b);
char* strcat(char* a, char* b);
int main()
{
	char a[MAX_LEN] = "qwertyz";
	char c[MAX_LEN];
	char b[MAX_LEN] = "qwertyzz";
	// printf("%i", strlen(a)); 
	// printf("%i", strcmp(a,b));
	// printf("%s", strcpy(c,b));
	printf("%s", strcat(a, b));
}
int strlen(char* a)
{
	int result = 0;
	for (int i = 0; i <= (MAX_LEN - 1); ++i)
	{
		if (a[i] != '\0')
		{
			result = result + 1;
		}
		else
		{
			break; 
		}
	}
	return result;
}
int strcmp(char* a, char* b)
{
	int result = 0;
	for (int i = 0; i <= (MAX_LEN - 1); ++i)
	{
		if (a[i] == '\0' && b[i] == '\0')
		{
			break;
		}
		if (a[i] > b[i])
		{
			result = 1;
			break;
		}
		if (a[i] < b[i])
		{
			result = -1;
			break;
		}
	}
	return result; 
}
char* strcpy(char* a, char* b)
{
	for (int i = 0; i <= (MAX_LEN - 1); ++i)
	{
		a[i] = b[i];
	}
	return a;
}
char* strcat(char* a, char* b)
{
	for (int i = 0; i <= (MAX_LEN - 1); ++i)
	{
		if (a[i] == '\0')
		{
			for (int n = 0; n <= (MAX_LEN - 1); ++n)
			{
				a[n + i] = b[n];
				if (b[n] == '\0')
				{
					break;
				}
			}
			break;
		}
	}
	return a;
}