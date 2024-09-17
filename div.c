#include <stdio.h>

int div(int divisor, int dividend) {
    int i = 0;
    if(dividend == 0) {
        printf("Error. Enter another dividend\n");
        return 0;
    }
    if(divisor > 0 && dividend > 0) {
        while(divisor >= dividend) {
            divisor -= dividend;
            i++;
        }
        if(divisor == 0) {
            return i;
        }
        else {
            return 0;
        }
    }
    if(divisor < 0 && dividend > 0) {
        while(divisor < 0) {
            divisor += dividend;
            i++;
        }
        if(divisor == 0) {
            return -i;
        }
        else {
            return 0;
        }
    }
    if(divisor > 0 && dividend < 0) {
        while(divisor > 0) {
            divisor += dividend;
            i++;
        }
        if(divisor == 0) {
            return -i;
        }
        else {
            return 0;
        }
    }
    if(divisor < 0 && dividend < 0) {
        while(divisor < 0) {
            divisor -= dividend;
            i++;
        }
        if(divisor == 0) {
            return i;
        }
        else {
            return 0;
        }
    }
    return 0;
}

int main() {
    int a, b;
    printf("Enter the divisor a:");
    scanf("%d", &a);
    printf("Enter the dividend b:");
    scanf("%d", &b);
    printf("a / b = %d\n", div(a, b));

    return 0;
}
