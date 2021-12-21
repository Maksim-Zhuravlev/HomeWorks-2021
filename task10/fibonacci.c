#include <stdio.h>
#include <stdlib.h>

int main(){
    int next, cur, prev;
    cur = 1;
    prev = 1;

    int i = 0;
    const int n = 10;

    while(i < 10){
        next = cur + prev;
        prev = cur;
        cur = next;
        i++;
    }

    printf("fib(%d) = %d\n", n, next);

    return 0;
}
