#include <stdio.h>
#define MAX_LEN 256

int strLen(const char *str)
{
    size_t count = 0;

    while (str[count] != '\n')
    {
        count += 1;
    }

    return count;
}

int strCmp(const char *str_1, const char *str_2)
{
    int len_str_1, len_str_2;
    len_str_1 = strLen(str_1);
    len_str_2 = strLen(str_2);

    if (len_str_1 > len_str_2)
    {
        return 1;
    }
    else if (len_str_1 < len_str_2)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < len_str_1; i++)
        {
            if (str_1[i] != str_2[i])
            {
                if (str_1[i] > str_2[i])
                {
                    return 1;
                }
                if (str_1[i] < str_2[i])
                {
                    return -1;
                }
            }
        }
        return 0;
    }
}

int main()
{
    char string_1[MAX_LEN];
    char string_2[MAX_LEN];

    printf("This program prints 0, 1 and -1 depending on the strings being compared.\n");
    printf("Enter the first string: ");
    fgets(string_1, MAX_LEN, stdin);
    printf("Enter the second string: ");
    fgets(string_2, MAX_LEN, stdin);
    printf("The resulting: %d\n", strCmp(string_1, string_2));

    return 0;
}