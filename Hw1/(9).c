#include<stdio.h>
#include<stdlib.h>
#include< string.h>
int main() {
    char str[100], q[100];
    int i = 0, e = 1, kolvo = 0, c = 0;
    scanf("%s%s", &str, &q);
    while (q[c] != '\0') {
        c++;
    }
    while (str[i - c] != '\0') {
        e = 1;
        for (int w = 0; w < c; w++)
        {
            if (q[w] != str[i + w]) e = 100;
        }
        if (e == 1) kolvo++;
        i++;
    }
    printf("%d", kolvo);
}