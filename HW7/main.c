#include <stdio.h>

void other() {
    printf("Other executed\n");
}


void input() {
    int array[1];
    int a;
    int i = 0;
    printf("Enter the address of other() on the 4 number. "
           "Enter 0 to stop.\n\n");
    while(1) {
        printf("Enter your %d number:", i + 1);
        scanf("%d", &a);
        i++;
        if (a == 0) {
            return;
        }
        else {
            array[i] = a;
        }
    }
}


void main() {
    printf("The address of other(): %d\n", other);
    input();
    printf("You are fine\n");
}
