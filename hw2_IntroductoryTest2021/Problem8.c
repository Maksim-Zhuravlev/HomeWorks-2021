#include<stdio.h>

int main() {
    int n = 600;
    int p[300];
    int max = 1;
    p[0] = 2;
    printf("%d\n", 2);
    for (int i = 3; i <= n; i += 2) {
        int f = 1;
        for (int j = 0; j < max; ++j) {
            if (i % p[j] == 0) {
                f = 0;
                break;
            }
        }
        if (f) {
            printf("%d\n", i);
            p[max] = i;
            ++max;
        }
    }
    return 0;
}