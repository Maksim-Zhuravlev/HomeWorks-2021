#include <stdlib.h>
#include <stdio.h>

int the_Sign( double arr) {
	if (arr == 0) {

		return 0;
	}
	if (arr > 0) {

		return 1;
	}
	else {

       return -1;
	}

}
int main() {

    long length;
    double arr;
	int sign = 1;

	printf("enter th length of your array: ");
	scanf("%ld", &length);
	if (length <= 0) {

		printf("Error, enter a number>0");
		exit(1);
	}
	for (int i = 0; i < length; i++) {
		printf("enter the element of the array:");
		scanf("%f", &arr );
		sign = sign * the_Sign(arr);
	}
	printf("The sign of ellements is: %d", sign);
	return 0;
}
