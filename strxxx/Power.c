#include <stdio.h>

int power(int a, int pow) {
    if (pow != 0) {
        return a * power(a, pow - 1);
    }
    else {
        return 1;
    }
}

int main() {
    int a, pow;
    printf("Enter your number:");
    scanf("%d", &a);
    printf("Enter the power:");
    scanf("%d", &pow);
    printf("Result: %d\n", power(a, pow));

    return 0;
}
