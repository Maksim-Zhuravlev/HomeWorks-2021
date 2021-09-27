#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s1[101], s[101];
    int k = 0;
    printf("Enter S (not more than 100 symbols): ");
    fgets(s, 100, stdin);
    fflush(stdin);
    printf("\nEnter S1 (not more than 100 symbols): ");
    fgets(s1, 100, stdin);
    fflush(stdin);
    int len_S = (int)strlen(s), len_S1 = (int)strlen(s1);
    for (int i = 0; i <= (len_S - len_S1); i++) {
        if (s[i] == s1[0]) {
            int ok = 1;
            for(int j = 1; j < len_S1 - 1; j++) {
                if (s1[j] != s[i + j]) {
                    ok = 0;
                    break;
                }
            }
            k += ok;
        }
    }
    printf("\nS1 is in S %d time(-s)", k);
    return 0;
}
