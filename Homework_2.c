#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1000
#define MAXLENGTH 100

float raisation_1(float number, int degree)
{
	return (pow(number, degree));
}

float raisation_2(float number, int degree)
{
	int i;
	float answer = 1;
	for (i = 0; i != degree; i++)
	{
		answer *= number;
	}
	return (answer);
}

int sign_of_array(int Array[], int length)
{
	int i, count = 0;
	bool flag = true;
	for (i = 0; i < length; i++)
	{
		if (Array[i] == 0)
		{
			flag = false;
			return printf("Array product sign = 0\n");
			break;
		}
		if (Array[i] < 0)
			count += 1;
	}
	if (count % 2 == 0)
		return printf("Array product sign = 1\n");
	else
		return printf("Array product sign = -1\n");
}

int palindrome(char *s)
{
	int i, j = 1, length, length_small;
	bool flag = true;
	length = strlen(s);
	length_small = strlen(s) / 2;
	for (i = 0; i < length_small; i++)
	{
		j++;
		if (s[i] != s[length - j])
		{
			flag = false;
			return printf("This string isn't palindrome!\n");
			break;
		}
	}
	if (flag)
		return printf("This string is palindrome!\n");
}

int fused_string(char *s)
{
	int i, count = 0;
	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] != ' ')
		{
			if (i != count)
				s[count] = s[i];
			count++;
		}
	}

	s[count] = '\0';
	return s;
}

int lower(char* s)
{
	int i, length = strlen(s);
	for (i = 0; i < length; i++)
	{
		s[i] = tolower(s[i]);

	}
	return s;
}

int simple_number(int number)
{
	int i;
	bool flag = true;
	for (i = 2; i <= pow(number, 0.5); i++)
	{
		if (number % i == 0)
		{
			flag = false;
			return 0;
			break;
		}
	}
	if (flag)
		return 1;
}

int all_simple(int number)
{
	int i;
	for (i = 2; i <= number; i++)
	{
		if (simple_number(i))
			printf("%d\n", i);
	}
}

int fibonachi(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n > 2)
		return fibonachi(n - 1) + fibonachi(n - 2);
}

int substrings(char *s, char *s1)
{
	int i, j, check, length_s, length_s1, count = 0;
	length_s = strlen(s);
	length_s1 = strlen(s1);
	for (i = 0; i < length_s - 1; i++)
	{
		for (j = 0; j < length_s1 - 1; j++)
		{
			if (s[i] == s1[j])
			{
				check = 1;
				while (s[i + check] == s1[j + check])
				{
					count++;
					check++;
				}
			}
		}
	}
	return count;
}

int main()
{
	//1.1
	float number;
	int degree;
	printf("Task 1.1.\nEnter the number: ");
	scanf("%f", &number);
	printf("Enter the degree: ");
	scanf("%d", &degree);
	printf("The number %f in degree %d = %f\n", number, degree, raisation_1(number, degree));
	//1.2
	printf("Task 1.2.\nEnter the number: ");
	scanf("%f", &number);
	printf("Enter the degree: ");
	scanf("%d", &degree);
	printf("The number %f in degree %d = %f\n", number, degree, raisation_2(number, degree));
	//2
	int array[MAXLENGTH];
	int i, length;
	printf("Task 2.\nEnter the length of array: ");
	scanf("%d", &length);
	printf("Enter the elements of array:\n");
	for (i = 0; i < length; i++)
		scanf("%d", &array[i]);
	sign_of_array(array, length);
	//3
	char line[MAXLINE];
	printf("Task 3.\nEnter the string:");
    getchar();
	fgets(line, MAXLINE, stdin);
	palindrome(lower(fused_string(line)));
	//4
	int number_3 = 0;
	printf("Task 4.\nEnter the number:");
	scanf("%d", &number_3);
	all_simple(number_3);
	//5
	char string[MAXLENGTH], string1[MAXLENGTH];
	printf("Task 6.\nEnter the string 1: ");
    getchar();
    fgets(string, MAXLINE, stdin);
	printf("Enter the string 2: ");
    getchar();
    fgets(string1, MAXLINE, stdin);
	printf("Number of occurrences: %d\n", substrings(string, string1));
	//6
	int n;
	printf("Task 5.\nEnter the n: ");
	scanf("%d", &n);
	printf("The number Fibonachi(%d) = %d\n", n, fibonachi(n));
}