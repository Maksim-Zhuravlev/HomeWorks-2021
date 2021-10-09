#include <stdio.h>


unsigned long long nth_fib(int n){
    if (n <= 2)
        return 1;

    unsigned long long prev = 1, curr = 1, tmp;
    for (int i = 0; i < n-2; i++){
        tmp = curr;
        curr = curr + prev;
        prev = tmp;
    }
    return curr;
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
    printf("%llu\n", nth_fib(n));
}
