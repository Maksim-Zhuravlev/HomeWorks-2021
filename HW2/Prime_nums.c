#include <stdio.h>

void prostye(int a) {
    if (a <= 2) {
        printf("There are no primes before this num.\n");
    }
    printf("Primes before this num: ");
    int n = 1;
    while(n < a) {
        int divs = 0;
        for(int i = 1; i < n; i++) {
            if (n % i == 0) {
                divs++;
            }
        }
        if (divs == 1) {
            printf("%d ", n);
        }
        n++;
    }
}

int main() {
    int a;
    printf("Enter your num:");
    scanf("%d", &a);
    prostye(a);

    return 0;
}
