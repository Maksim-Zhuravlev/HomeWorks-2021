#include <stdio.h>

void primeNumbers(int num) {
    if (num <= 2) {
        printf("No primes.\n");
    }
    int n = 1;
    while(n < num) {
        int count = 0;
        for(int i = 1; i < n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        if (count == 1) {
            printf("%d\n", n);
        }
        n++;
    }
}

int main() {
    int num;
    printf("Enter your num:");
    scanf("%d", &num);
    primeNumbers(num);
    return 0;
}
