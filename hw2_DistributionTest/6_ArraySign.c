#include<stdio.h>

int main() {
	int len, el = 1;
	int sign = 1;
	printf("Enter the length of the array:");
	scanf("%d", &len);
	for (int i = 0; i < len; i++) {
		printf("Enter the element of the array:");
		scanf("%d", &el);
		int elSign = 1;
		if (el == 0) {
			elSign = 0;
		}
		if (el > 0) {
			elSign = 1;
		}
		if (el < 0) {
			elSign = -1;
		}
		sign = sign * elSign;
	}
	printf("The sign is: %d", sign);
	return 0;
}