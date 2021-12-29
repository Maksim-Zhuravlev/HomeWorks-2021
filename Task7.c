#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void palindrome(char* str) {
    int sign = 1;
    int i, j;
    j = strlen(str);
    for (i = 0; i < j; i++) {
        if (tolower(str[i]) != tolower(str[j - i - 1])) {
            sign = sign * 0;
        }
        else {
            sign = sign * 1;
        }
    }
    if (sign > 0) {
        printf("This is a palindrome");
    }
    else {
        printf("This is not a palindrome");
    }
}



int main() {
    char str[256];
    printf("Enter your string:");
    char* str1 = gets(str);
    int end = 0;
    for (int i = 0; i < strlen(str1); i++) {
        if (str1[i] != ' ' && str1[i] != ',' && str1[i] != '.' && str1[i] != '!' && str1[i] != '?') {
            if (i != end) {
                str1[end] = str1[i];
            }
            end++;
        }
    }
    str1[end] = '\0';
    palindrome(str1);
    return 0;
}