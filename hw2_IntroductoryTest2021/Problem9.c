#include<stdio.h>
#include<string.h>

int main() {
    char s[80] = "FO Fo FFFffFF";
    char s1[80] = "F";
    int lenS = strlen(s);
    int lenS1 = strlen(s1);
    int kol = 0;
    for (int i = 0; i <= lenS - lenS1; ++i) {
        int f = 1;
        for (int j = 0; j < lenS1; ++j) {
            if (s1[j] != s[i + j]) {
                f = 0;
                break;
            }
        }
        if (f) {
            ++kol;
        }
    }
    printf("%d\n", kol);
    return 0;
}