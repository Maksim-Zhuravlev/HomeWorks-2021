#include<stdio.h>
#include<string.h>

int main() {
    char s[100] = "I prefer Pi";
    printf("%s\n", s);

    int i = 0;
    int len = strlen(s) - 1;

    while (i < len) {
        while (!(s[i] - ' ')) {
            i += 1;
        }
        while (!(s[len] - ' ')) {
            len -= 1;
        }
        char si = s[i];
        char sl = s[len];
        if (si < 'a') {
            si += 'a' - 'A';
        }
        if (sl < 'a') {
            sl += 'a' - 'A';
        }
        if (si != sl) {
            printf("This string is not a Palindrome\n");
            return 0;
        }
        i += 1;
        len -= 1;
    }
    printf("This string is a Palindrome\n");
    return 0;
}