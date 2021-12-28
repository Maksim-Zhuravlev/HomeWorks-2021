#include <stdio.h>
#include<ctype.h> 

int div(int dividend, int divisor){
    int i = 0;
    if(dividend > 0 && divisor > 0){
        while( dividend >= divisor ){
            dividend -= divisor;
            i++;
        } if (dividend == 0) {
            return i;
        } else {
            return 0;
        }
    }
    
    if (dividend < 0 && divisor > 0){
        while( dividend < 0 ){
            dividend += divisor;
            i--;
        } if (dividend == 0) {
            return i;
        } else {
            return 0;
        }
    }
    
    if (dividend > 0 && divisor < 0){
        while( dividend > 0){
            dividend += divisor;
            i--;
        } if (dividend == 0) {
            return i;
        } else {
            return 0;
        }
    }

    if (dividend < 0 && divisor <0){
        while( dividend <= divisor){
            dividend -= divisor;
            i++;
        } if (dividend == 0) {
            return i;
        } else {
            return 0;
        }
    }
    if( divisor == 0){
        printf("Please, enter another dividend");
        return 0;
    }
    return 0;
}

int main(){
    int x,y;
    printf("Enter dividend x:\n");
    scanf("%d", &x);
    printf("Enter divisor y:\n");
    scanf("%d", &y);
    printf("x / y = %d\n", div(x, y));
    return 0;
}