#include <stdio.h>
#include <math.h>


double power(double num, int pwr) {
    if (pwr == 0) {
        return 1;
    } else if (pwr <= 0) {
        return power(1 / num, -pwr);
    }

    int log = (int) log2f(pwr);
    double ret = 1;
    double powers[log + 1];
    powers[0] = num;

    for (int i = 1; i <= log; i++) {
        powers[i] = powers[i - 1] * powers[i - 1];
    }
    for (int i = 0; i <= (int) log2f(pwr); i++) {
        if (pwr & (1 << i)) {
            ret *= powers[i];
        }
    }

    return ret;
}


int main() {
    int n;
    double x;

    for (int i = 0; i < 10; i++) {
        scanf("%lf %d", &x, &n);
        printf("%g\n", power(x, n));
    }

    return 0;
}
























