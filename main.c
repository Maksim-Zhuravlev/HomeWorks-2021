#include <stdio.h>
#include <stdlib.h>

int main()
{
    int primeNumber, x, i ;
    printf("Please enter a number:");
    scanf("%d",&x);
    primeNumber = 1;
    for (i=2;i<=x/2;i++){
        if (x%i==0){
            primeNumber=0;
            break;
        }
    }
    if (primeNumber==1){
            printf("%d is a prim number", x);
                   }
    else {
        printf("%d is not prime number", x);
    }
    return 0;
}
