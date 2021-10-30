#include <stdio.h>
#define MAX_LEN 256

int strLen(const char *str)
{
    size_t count = 0;
    while (str[count] != '\n')
    {
        count++;
    }

    return count;
}

int main()
{
    char string[MAX_LEN];

    printf("This program prints lenght of the string.\n");
    printf("Enter the string: ");
    fgets(string, MAX_LEN, stdin);
    printf("The lenght of the string: %d\n", strLen(string));

    return 0;
}