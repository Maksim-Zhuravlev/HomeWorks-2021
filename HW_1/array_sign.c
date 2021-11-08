#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>


int array_sign(const int *array, int size) {
    int sign = 1;
    for (int i = 0; i < size; i++) {
        if (!array[i]) {
            return 0;
        } else if (array[i] < 0) {
            sign *= -1;
        }
    }
    return sign;
}


int main() {
//    srand(time(NULL));
//    int size = 20;
//    int array[size];
//    for (int i = 0; i < size; i++){
//        array[i] = rand() % 101 - 50;
//        printf("%d ", array[i]);
//    }

    int size;
    scanf("%d", &size);
    int array[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("\n%d\n", array_sign(array, size));
}
