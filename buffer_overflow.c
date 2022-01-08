#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void other() {
    printf("Other was called.\n");
    exit(1);
}

int input() {
    int data[1];
    int x = 0;
    int i = 0;

    while (1)
    {
        printf("Enter number:");
        scanf("%d", &x);
        if (0 == x)
        {
            other();
        }
        data[i++] = x;
    }
}

int main() {
    int a = input();
    printf("a = %i\n", a);
    input();
    return;
}