#include <stdio.h>


void main() {
    int s;
	
    printf("Input length of an array: ");
    scanf("%d", &s);
    if (s == 0) {
        printf("\nAn empty array");
    } else if (s < 0) {
        printf("\nInput positive number!");
    } else {
        int n = 0, z = 0;
        int x;
		
        printf("\nInput elements of the array");
        for (int i = 0; i < s; i++) {
            printf("\nElement is ");
            scanf("%d", &x);
            if (x < 0) {
                n++;
            } else if (x == 0) {
                z = 1;
                break;
            }
        }
        if (z == 1) {
            printf("\nMultiplication is 0");
        } else if (n % 2 == 1) {
            printf("\n-");
        } else {
            printf("\n+");
        }
    }
	printf("\n");
}
