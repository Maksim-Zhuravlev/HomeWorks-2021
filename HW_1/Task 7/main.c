#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256

int main()
{
    char string[MAX_LEN];
    int j = 1;
    int f = 0;
    int len_str;

    printf("This program prints if the string is palindrome or not.\n");
    printf("Enter the string: ");
    fgets(string, MAX_LEN, stdin);

    len_str = strlen(string);

    for (int i = 0; i <= len_str; i++)
    {
        string[i] = (char)tolower(string[i]);
    }

    for (int i = 0; string[i] != '\n'; i++)
    {
        if (string[i] == ' ')
        {
            for (int q = i; string[q] != '\0'; q++)
            {
                string[q] = string[q + 1];
            }
            i--;
            len_str -= 1;
        }
    }

    for (int i = 0; i < (len_str / 2); i++)
    {
        j++;
        if (string[i] != string[len_str - j])
        {
            f = 1;
            break;
        }
    }

    if (f == 0)
    {
        printf("This string is palindrome.\n");
    }
    else
    {
        printf("This string isn't palindrome.\n");
    }
    return 0;
}