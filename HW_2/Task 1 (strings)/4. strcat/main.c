#include <stdio.h>

#define MAX_LEN 256

void strCat(char *str_1, const char *str_2)
{
    int i, j;

    for (i = 0; str_1[i] != '\n'; i++)
    {
        ;
    }
    for (j = 0; str_2[j] != '\n'; j++)
    {
        str_1[i + j] = str_2[j];
    }

    str_1[i + j] = '\0';
}

int main()
{
    char string_1[MAX_LEN], string_2[MAX_LEN];

    printf("This program concatenates the first string with the second string.\n");
    printf("Enter the first string: ");
    fgets(string_1, MAX_LEN, stdin);
    printf("Enter the second string: ");
    fgets(string_2, MAX_LEN, stdin);
    strCat(string_1, string_2);
    printf("The resulting string: %s\n", string_1);

    return 0;
}