#include <stdio.h>
#include <string.h>

int main() {
    char string1[50], string2[50];
    printf("The substring:");
    gets(string2);
    printf("The smaller string:");
    gets(string1);
    int count = 0;
    int leng = strlen(string2);
    for(int i = 0; i < leng; i++) {
        if (*string1 == string2[i]) {
            count++;
        }
    }
    printf("There are %d smaller strings in the substring.\n", count);
    return 0;
}
