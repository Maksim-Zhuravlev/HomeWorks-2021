#include <stdio.h>
#define ELEMENTS 5        //количество элементов в массиве

int main() {
    int list_of_int[ELEMENTS] = {};
    //----------считываются элементы массива---------------
    for(int i = 0; i < ELEMENTS; i++) {
        if (i + 1 == 1) {
            printf("Enter the %dst number:", i + 1);
            scanf("%d", &list_of_int[i]);
        }
        else if (i + 1 == 2) {
            printf("Enter the %dnd number:", i + 1);
            scanf("%d", &list_of_int[i]);
        }
        else if (i + 1 == 3) {
            printf("Enter the %drd number:", i + 1);
            scanf("%d", &list_of_int[i]);
        }
        else {
            printf("Enter the %dth number:", i + 1);
            scanf("%d", &list_of_int[i]);

        }
    }
    //-----------------------------------------------------
    int a = 1;
    for(int i = 0; i < ELEMENTS; i++) {
        a *= list_of_int[i];
    }
    printf("Sign: ");
    if (a < 0) {
        printf("-\n");
    }
    else if (a > 0) {
        printf("+\n");
    }
    else {
        printf("0\n");
    }

    return 3;
}
