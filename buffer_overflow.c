#include <stdio.h>



void other() {
    printf("HEHEHEHEHE\n");
}



void input() {
    int arr[1];
    int a;
    int i = 0;
    printf("Write the adress of other() on the 5th number.\n");
    printf("If you want to quit enter 0.\n");
    while (1) {
        printf("Enter number %d:", i + 1);
        scanf("%d", &a);
        i++;
        if (a == 0) {
            return;
        }
        else {
            arr[i] = a;
        }
    }
}



void main() {
    printf("%d\n", other);
    input();
    printf("The end\n");
}