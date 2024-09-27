#include <stdio.h>

#define MAX_LEN 256

int strlen(char myString[MAX_LEN])
{
	int i = 0, res = -1;
	for (i; i < MAX_LEN; i++)
	{
		if (myString[i] == '\0')
		{
			res = i;
			i = MAX_LEN;
		}
	}
	return res;
}

int strcmp(char myString1[MAX_LEN], char myString2[MAX_LEN])
{
	int i = 0, res = 0, m1, m2, m;
	m1 = strlen(myString1);
	m2 = strlen(myString2);
	if (m1 < m2)
	{
		m = m1;
	}
	else
	{
		m = m2;
	}
	for (i; i < m; i++)
	{
		if (myString1[i] != myString2[i])
		{
			if (myString1[i] > myString2[i])
			{
				res = 1;
			}
			else
			{
				res = -1;
			}
			i = MAX_LEN;
		}
	}
	if (res == 0)
	{
		if (m1 < m2)
		{
			res = -1;
		}
		else if (m1 > m2)
		{
			res = 1;
		}
	}
	return res;
}

void strcpy(char *myString1, char *myString2)
{
	while (*myString2 != '\0')
	{
		*myString1 = *myString2;
		myString1++;
		myString2++;
	}
	*myString1 = '\0';
}

void strcat(char *myString1, char *myString2)
{
	int len = 1;
	while (*myString1 != '\0')
	{
		len++;
		myString1++;
	}
	while (len < MAX_LEN && *myString2 != '\0')
	{
		*myString1 = *myString2;
		myString1++;
		myString2++;
		len++;
	}
	*myString1 = '\0';
	myString1 -= (len-1);
	if (*myString2 != '\0')
	{
		*myString1 = '\0';
	}
}

int main()
{
	//strlen
	/*
	char myString[MAX_LEN];
	printf("Enter the string: ");
	scanf("%s", myString);
	printf("String length: %d.\n", strlen(myString));
	*/
	//strcmp
	/*
	char myString1[MAX_LEN], myString2[MAX_LEN];
	printf("Enter the first string: ");
	scanf("%s", myString1);
	printf("Enter the second string: ");
	scanf("%s", myString2);
	printf("strcmp(the first string, the second string) = %d.\n", strcmp(myString1, myString2));
	*/
	//strcpy
	/*
	char myString1[MAX_LEN], myString2[MAX_LEN];
	printf("Enter the first string: ");
	scanf("%s", myString1);
	printf("Enter the second string: ");
	scanf("%s", myString2);
	strcpy(myString1, myString2);
	printf("strcpy(the first string, the second string) = %s.\n", myString1);
	*/
	//strcat
	char myString1[MAX_LEN], myString2[MAX_LEN];
	printf("Enter the first string: ");
	scanf("%s", myString1);
	printf("Enter the second string: ");
	scanf("%s", myString2);
	strcat(myString1, myString2);
	if (myString1[0] == '\0')
	{
		printf("The resulting string is longer than MAX_LEN - 1.");
	}
	else
	{
		printf("strcat(the first string, the second string) = %s.\n", myString1);
	}
	return 0;
}