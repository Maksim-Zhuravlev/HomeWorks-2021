#include <stdio.h>

void other() {
    printf("This is not the end of main()!\n");
}


void input() {
    int array[1];
    int a;
    int i = 0;
    printf("Enter the address of other() on the 5 number.\n");
    printf("Then, enter 0 to stop.\n");
    while (1) {
        printf("Enter %d number:", i + 1);
        scanf("%d", &a);
        i += 1;
        if (a == 0) {
            return;
        }
        else {
            array[i] = a;
        }
    }
}


void main() {
    printf("The address of other() is %d\n", other);
    input();
    printf("This is the end of main()\n");
}