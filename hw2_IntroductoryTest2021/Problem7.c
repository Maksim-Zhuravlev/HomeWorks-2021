#include<stdio.h>
#include<string.h>

int main() {
    char s[80] = "I prefer Pi";
    printf("%s\n", s);

    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        while (!(s[i] - ' ')) ++i;
        while (!(s[j] - ' ')) --j;
        char si = s[i];
        char sj = s[j];
        if (si < 'a') {
            si += 'a' - 'A';
        }
        if (sj < 'a') {
            sj += 'a' - 'A';
        }
        if (si != sj) {
            printf("-\n");
            return 0;
        }
        ++i; --j;
    }
    printf("+\n");
    return 0;
}