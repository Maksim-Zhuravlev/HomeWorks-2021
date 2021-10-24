/*
1. Написать свою реализацию функций для работы со строками из стандартной библиотеки:
- strlen,
- strcmp,
- strcpy,
- strcat.
Строки использовать фиксированной длины. Например, MAX_LEN 256.
 */
#include <stdio.h>
#include <string.h>


#define MAX_LEN 256


size_t strlen_(const char *str) {
    size_t i = 0;
    while (str[i] != '\0')
        i++;

    return i;
}


int strcmp_(const char *lhs, const char *rhs) {
    int i = 0;
    while (lhs[i] == rhs[i] && lhs[i] != '\0')
        i++;

    return (lhs[i] < rhs[i]) ? -1 : (lhs[i] > rhs[i] ? 1 : 0);
}


char *strcpy_(char *dest, const char *src) {
    int i = 0;
    do
        dest[i] = src[i];
    while (src[i++] != '\0');

    return dest;
}


char *strcat_(char *dest, const char *src) {
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i++;

    do {
        dest[i] = src[j];
        i++;
        j++;
    } while (src[j] != '\0');

    return dest;
}


int main() {
    char empty_string[] = "";
    char string[] = "Hello World!";
    char string_2[] = "Hello World!!!";
    char string_3[] = " Goodbye, World!";
    char long_string[MAX_LEN];

    printf("Length of string '%s' = %zu\n", empty_string, strlen_(empty_string));
    printf("Length of string '%s' = %zu\n\n", string, strlen_(string));

    printf("'%s' %d '%s'\n", string_2, strcmp_(string_2, string), string);
    printf("'%s' %d '%s'\n", empty_string, strcmp_(empty_string, string), string);
    printf("'%s' %d '%s'\n", string, strcmp_(string, string), string);
    printf("'%s' %d '%s'\n\n", empty_string, strcmp_(empty_string, empty_string), empty_string);

    printf("StrCmp_: %s\n\n", strcpy_(long_string, string));

    strcat_(long_string, string_3);
    printf("StrCat_: %s\n", long_string);

    return 0;
}