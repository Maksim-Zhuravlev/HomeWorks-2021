#include <stdio.h>
#include <string.h>
#include <ctype.h>

void isPalindrome(char *string) {
    int palindrome = 0;
    int i, len;
    len = strlen(string);
    for (i = 0; i < len; i++) {
        if (tolower(string[i]) != tolower(string[len - i - 1])) {
            palindrome += 0;
        }
        else {
            palindrome += 1;
        }
    }
    if(palindrome > 0) {
        printf("Yes, palindrome");
    }
    else {
        printf("No, not a palindrome");
    }
}

int main() {
    char string[100];
    printf("String:");
    char *string1 = gets(string);

    int end = 0;
    for (int i = 0; i < strlen(string1); i++) {
        if (string1[i] != ' ') {
            if (i != end) {
                string1[end] = string1[i];
            }
            end++;
        }
    }
    string1[end] = '\0';

    isPalindrome(string1);
    return 0;
}

