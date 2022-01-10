#include <stdio.h>


int fibonacci(int c) {
    int num1 = 1;
    int num2 = 2;
    int b;
    for (int i = 3; i <= (c - 1); i++) {
        b = num1;
        num1 = num2;
        num2 = b + num1;
    }
    return num1;
}


int main(){
    int a;
    printf("Enter your fibonacci number: ");
    scanf("%d",&a);
    printf("%d", fibonacci(a));
    return 0;
}