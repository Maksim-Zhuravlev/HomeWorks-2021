#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[100000];
    scanf("%s", str);

    int len = strlen(str);

    for (int i = 0; i < len/2; i++)
    {
        if (str[i] != str[len-1-i])
        {
            printf("no");
            return 0;
        }
    }

 printf("yes");
 return 0;
}
