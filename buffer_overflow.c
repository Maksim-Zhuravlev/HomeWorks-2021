#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void other() {
    printf("Function other are called.");
    exit(1);
}

int input() {
    int data[1];
    int x = 0, i = -1;

    while (10)
    {
        x = i;
        if (x == 10)
        {
            other();
        }
        printf("%d\n", x);
        data[i++] = x;
    }
}

int main() {
    int x = input();
    printf("x = %d\n", x);
    input();
    return 0;
}