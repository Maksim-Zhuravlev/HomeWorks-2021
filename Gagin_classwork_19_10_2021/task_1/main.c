#include <stdio.h>
#include <stdlib.h> // For "malloc" function.

long long strLen(const char *str)
{
	long long len = 0;
	for (int i = 0; str[i] != '\n' ; i++)
	{
		len += 1;
	}
	return len;
}

long long strCmp(const char *str_1, const char *str_2)
{
	if (strLen(str_1) < strLen(str_2))
	{
		return -1;
	}
	if (strLen(str_1) > strLen(str_2))
	{
		return 1;
	}
	for (int i = 0; i < strLen(str_1); i++)
	{
		if ((int) str_1[i] < (int) str_2[i])
		{
			return -1;
		}
		if ((int) str_1[i] > (int) str_2[i])
		{
			return 1;
		}
	}
	return 0;

}

void strCpy(const char *str_1, char *str_2)
{
	int i;
	for (i = 0; str_1[i] != '\0'; i++)
	{
		str_2[i] = str_1[i];
	}
	str_2[i] = str_1[i];
}

void strCat(char *str_1, const char *str_2)
{
	int i;
	long long len_1 = strLen(str_1);
	for (i = 0; str_2[i] != '\0'; i++)
	{
		str_1[i + len_1] = str_2[i];
	}
	str_1[i + len_1] = str_2[i];
}

int main() {
	const short MaxLenOfStr = 500;
	char *str_1 = (char *) malloc(sizeof(char) * MaxLenOfStr);
	char *str_2_1 = (char *) malloc(sizeof(char) * MaxLenOfStr);
	char *str_2_2 = (char *) malloc(sizeof(char) * MaxLenOfStr);
	char *str_3_1 = (char *) malloc(sizeof(char) * MaxLenOfStr);
	char *str_3_2 = (char *) malloc(sizeof(char) * MaxLenOfStr);
	char *str_4_1 = (char *) malloc(sizeof(char) * (MaxLenOfStr * 2));
	char *str_4_2 = (char *) malloc(sizeof(char) * MaxLenOfStr);

	printf("This program demonstrate own functions 1)strlen, 2)strcmp, 3)strcpy, 4)strcat.\n");
	printf("1)Please, enter the string, which one has not more than\n500 symbols:");
	fgets(str_1, MaxLenOfStr, stdin);
	long long len =  strLen(str_1);
	printf("Here we go. There is len of your string:%lld\n", len);

	printf("2)Please, enter the first string, which one has not more than\n500 symbols:");
	fgets(str_2_1, MaxLenOfStr, stdin);
	printf("Now, enter the second string:");
	fgets(str_2_2, MaxLenOfStr, stdin);
	printf("Here we go. There is a result of function strcmp:%lld\n", strCmp(str_2_1, str_2_2));

	printf("3)Please, enter the string:");
	fgets(str_3_1, MaxLenOfStr, stdin);
	strCpy(str_3_1, str_3_2);
	printf("There is copied string:%s", str_3_2);

	printf("4)Please, enter the string:");
	fgets(str_4_1, MaxLenOfStr * 2, stdin);
	printf("Now, enter the second string:");
	fgets(str_4_2, MaxLenOfStr, stdin);
	strCat(str_4_1, str_4_2);
	printf("Here we go. There is your united string:%s\n", str_4_1);
	return 0;

}
