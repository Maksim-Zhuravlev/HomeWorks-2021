#include <stdio.h>
#include <stdlib.h>

unsigned division(unsigned x, unsigned y) {
    if (x < y)
    {
        printf("The remainder is %d\n", x);
        return 0;
    }

    return 1 + division(x - y, y);
}

int divide(int x, int y) {

    if (y == 0) {
        printf("Error!! Divisible by 0");
        exit(-1);
    }

    int sign = 1;

    if (x * y < 0) {
        sign = -1;
    }

    return sign * division(abs(x), abs(y));
}

int main() {
    int dividend = 22;
    int divisor = -7;

    printf("The quotient is %d\n", divide(dividend, divisor));

    return 0;
}
