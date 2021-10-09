#include <stdio.h>


void primes(int n){
    if (n < 2)
        return;

    int prime[n];
    int c = 1;
    prime[0] = 2;

    for (int i = 3; i <= n; i += 2){
        int is_prime = 1;

        for (int j = 1; j < c; j++) {
            if (prime[j] * prime[j] > i)
                break;
            else if (!(i % prime[j])) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime){
            prime[c] = i;
            c++;
        }
    }
    for (int i = 0; i < c; i++)
        printf("%d\t", prime[i]);
}


void scan_int(int *n){
    short success = 0;
    char newline;

    do{
        printf("n = ");
        if (scanf("%d%c", n, &newline) != 2 || newline != '\n'){
            printf("Invalid input\n");
            while(getchar() != '\n');
        }
        else{
            success = 1;
        }
    } while (!success);
}


int main(){
    int n;
    scan_int(&n);
    primes(n);
}
