#include <stdio.h>

void other() {
    printf("Completed\n");
}

void input() {
    long long m[1];
    long long x = 1;
    long long i = 0;
    printf("Other: %lld\n", &other);
    while(x) {
        scanf("%lld", &x);
        m[i++] = x;
    }
}

int main() {
    input();
    printf("No completed\n");
    return 0;
}

