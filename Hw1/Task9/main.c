#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s1[] = "12", s[] = "123454212";
    int k = 0, size_Of_S = sizeof(s) / sizeof(s[0]), size_Of_S1 = sizeof(s1) / sizeof(s1[0]);
    printf("S: %d\nS1: %d", size_Of_S, size_Of_S1);
    for (int i = 0; i <= size_Of_S - size_Of_S1; i++) {
        if (s[i] == s1[0]) {
            int ok = 1;
            for(j = 1; j < size_Of_S1; j++) {
                if (s1[j] != s[i + j]) {
                    ok = 0;
                    break;
                }
            }
            k += ok
        }
    }
    printf("k = %d", k);
    return 0;
}
