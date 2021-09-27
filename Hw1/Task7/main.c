#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
   char s[101], s2[101];
   printf("Enter your phrase without any punctuation marks (no more than 100 symbols): ");
   fgets(s, 100, stdin);
   fflush(stdin);
   int len_s = (int)strlen(s) - 1, k = 0, poly = 1, len_s2;
   if (len_s == 0) {
    printf("\nAn empty string\n");
    return 0;
   }
   for (int i = 0; i < len_s; i++) {
    if (s[i] != ' ') {
        s2[k] = toupper(s[i]);
        k++;
    }
   }
   for (int i = k; i < 101; i++) {
    s2[i] = '\0';
   }
   len_s2 = (int) strlen(s2);
   for (int i = 0; i < len_s2 / 2; i++) {
    if (s2[i] != s2[len_s2 - i - 1]) {
        poly = 0;
        break;
    }
   }
   if (poly) {
    printf("\nThis is a polyndrome!\n");
   } else {
       printf("\nThis is not a polyndrome :c\n");
   }
   return 0;
}
