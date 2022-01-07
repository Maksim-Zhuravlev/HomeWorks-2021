#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

long powerFast(long num, long deg) {
    long result = 1;
    while (deg) {
        if (deg % 2 == 0) {
            deg /= 2;
            num *= num;
        }
        else {
            deg--;
            result *= num;
        }
    }

    return result;
}

int main() {

    int number, degree;
    printf("Enter the number:\n");
    scanf("%d", &number);
    printf("Enter the degree:\n");
    scanf("%d", &degree);
    printf("Your new number is %d", powerFast(number, degree));

    return 0;
}