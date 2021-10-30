#include <stdio.h>

#define MAX_LEN 256

void strCpy(char *str_1, char *str_2)
{
    int i = 0;

    while (str_1[i] != '\0')
    {
        str_1[i] = str_2[i];
        i++;
    }
    str_1[i] = str_2[i];
}

int main()
{
    char string_1[2 * MAX_LEN], string_2[MAX_LEN];

    printf("This program copies the second string to the first string.\n");
    printf("Enter the first string: ");
    fgets(string_1, MAX_LEN, stdin);
    printf("Enter the second string: ");
    fgets(string_2, MAX_LEN, stdin);
    strCpy(string_1, string_2);
    printf("The resulting string: %s", string_1);

    return 0;
}