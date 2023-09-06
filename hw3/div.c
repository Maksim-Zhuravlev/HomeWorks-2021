#include <stdio.h>

int div(int divisor, int divident) {
    if (divisor == 0) {
        return 0;
    }
    int g = 0;
    int flag = 0;
    if (divisor < 0 && divident < 0) {
        flag = 0;
        divisor = -divisor;
        divident = -divident;
    } else if (divisor > 0 && divident < 0) {
        flag = 1;
        divident = -divident;
    } else if (divisor < 0 && divident > 0) {
        flag = 1;
        divisor = -divisor;
    }
    while (divisor >= divident) {
        divisor = divisor - divident;
        g++;
    }
    if (flag == 1) {
        g = -g;
    }
    return g;
}

int main() {
    printf("%d", div(0, -5));
    return 0;
}
