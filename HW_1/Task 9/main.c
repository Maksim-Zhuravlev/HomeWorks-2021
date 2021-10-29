#include <stdio.h>
#include <string.h>
#define MAX_LEN 256

int main()
{
    size_t num_chars = MAX_LEN;
    char *str = (char *)malloc(sizeof(char) * num_chars);
    char *substr = (char *)malloc(sizeof(char) * num_chars);
    int count = 0;
    int len_str, len_substr;

    printf("This program finds the count of occerrences String_1 in String as substring.\n");
    printf("Enter the string: ");
    fgets(str, num_chars, stdin);
    printf("Enter the substring: ");
    fgets(substr, num_chars, stdin);

    len_str = strlen(str);
    len_substr = strlen(substr);

    for (int i = 0; i < (len_str - len_substr) + 1; i++)
    {
        int f = 0;
        int k = 0;

        for (int j = 0; j < len_substr - 1; j++)
        {
            if (str[k + i] != substr[j])
            {
                f = 1;
                break;
            }
            k += 1;
        }
        if (f == 0)
        {
            count += 1;
        }
    }
    printf("%d \n", count);
    return 0;
}