#include <stdio.h>


int div(int divisor, int divident) {
    int x = 1;
    int ans = 0;
    int sign = 1;
    if (divident == 0) {
        printf("Error, the divident is 0\n");
            return 0;
    }
    if (divisor < 0) {
        sign *= -1;
        divisor *= -1;
    }
    if (divident < 0) {
        sign *= -1;
        divident *= -1;
    }
    while (divident <= divisor) {
        divident <<= 1;
        x <<= 1;
    }
    while (x > 1) {
        divident >>= 1;
        x >>= 1;
        if (divisor >= divident) {
            divisor -= divident;
            ans += x;
        }
    }
    if (divisor != 0) {
        return 0;
    }
    return ans * sign;
}

int main() {
    int divisor;
    int divident;
    printf("Enter divisor:\n");
    scanf("%d", &divisor);
    printf("Enter divident:\n");
    scanf("%d", &divident);
    printf("%d/%d = %d", divisor, divident, div(divisor, divident));
    return 0;
}