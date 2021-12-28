#include <stdio.h>
#include <math.h>

int main(){
    int a, b, result;
    printf("Enter two  numbers for exponential function\n");
    scanf("%d %d", &a, &b);
    result = pow(a, b);
    printf("a^b= %d", result);
    return 0;
}