#include <stdio.h>
#include <string.h>
#define SIZE 100

int main() {
    char str1[SIZE], str2[SIZE];
    int n = 0;
    printf("Enter the 1st string:");
    gets(str1);
    printf("Enter the 2nd string:");
    gets(str2);
    for(int i = 0; i < strlen(str2); i++) {
        if (*str1 == str2[i]) {
            n++;
        }
    }
    printf("%d", n);

    return 0;
}
