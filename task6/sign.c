#include <stdio.h>
#define SIZE 3

int main() {
    int listInt[SIZE] = {};
    for(int i = 0; i < SIZE; i++) {
        printf("Enter the next number:", i + 1);
        scanf("%d", &listInt[i]);
    }
    int a = 1;
    for(int i = 0; i < SIZE; i++) {
        a *= listInt[i];
    }
    printf("The sign is: ");
    if(a < 0) {
        printf("-\n");
    }
    else if(a > 0) {
        printf("+\n");
    }
    else {
        printf("0\n");
    }

    return 0;
}
