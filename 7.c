
#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
int other() {
    printf(":-))");
    exit(1);
}
int input() {
    int stop = 0;
    int data[2];
    void* pointer = &other;
    int i = 0, counter = 8;
    while (counter--)
    {
        printf("%d\n", i + 1);
        data[i++] = pointer;
    }
    return 0;
}
int main()
{
    printf("start\n");
    printf("%p\n", &other);
    input();
    printf("end\n");
}