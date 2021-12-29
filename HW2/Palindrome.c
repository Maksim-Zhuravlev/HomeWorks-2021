#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 256

void palindrome(char *str) {
    int sign = 1;
    int i, z;
    z = strlen(str);
    for (i = 0; i < z; i++) {
        if (tolower(str[i]) != tolower(str[z - i - 1])) {
            sign = sign * 0;
        }
        else {
            sign = sign * 1;
        }
    }
    if(sign > 0) {
        printf("This is a palindrome");
    }
    else {
        printf("This is not a palindrome");
    }
}

int main() {
    char str[SIZE];
    printf("Enter your string:");
    char *str1 = gets(str);
        // delete spaces
    int end = 0;
    for (int i = 0; i < strlen(str1); i++) {
        if (str1[i] != ' ') {
            if (i != end) {
                str1[end] = str1[i];
            }
            end++;
        }
    }
    str1[end] = '\0';
        //
    palindrome(str1);

    return 0;
}
