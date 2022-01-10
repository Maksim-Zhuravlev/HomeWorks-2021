#include<stdio.h>

int main(){
    int length;
    int a = 1;
    int sign = 1;
    int temporary = 1;
    printf("Enter the length of an array:");
    scanf("%d", &length);
    for (int i = 0 ; i < length; i++ ){
        printf("Enter the element of your array:");
        scanf("%d",&a);
        if (a > 0){
            temporary = 1; 
        } else if (a == 0) {
            temporary = 0;
        } else {
            temporary = -1;
        }
        sign = sign*temporary;

    }
    printf("The sign of your array is:%d", sign);
    return 0;
}