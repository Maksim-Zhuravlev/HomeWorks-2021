#include <stdio.h>
#include <string.h>
#define LEN 256


int main() {
    char str1[LEN], str2[LEN];
    int a = 0;
    printf("Enter the first string:");
    gets(str1);
    printf("Enter the second string:");
    gets(str2);
    for(int i = 0; i < strlen(str2); i++) {
        if (*str1 == str2[i]) {
            a++;
        }
    }
    printf("%d", n);

    return 0;
}