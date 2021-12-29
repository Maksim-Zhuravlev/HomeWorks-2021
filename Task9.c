#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int substrings(char* s, char* s1)
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

int main() {
    char string1[MAX_LENGTH], string2[MAX_LENGTH];
    printf("Enter the string 1: ");
    scanf("%s", string1);
    printf("Enter the string 2: ");
    scanf("%s", string2);
    printf("Number of occurrences: %d\n", substrings(string1, string2));
}