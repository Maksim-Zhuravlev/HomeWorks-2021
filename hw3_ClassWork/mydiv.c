#include <stdlib.h>
#include <stdio.h>

int myDiv(int dividend, int divisor) {
	int s = 1;
	if ((divisor == 0) || (dividend == 0)) {
		return 0;
	}
	if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
		s = -1;
	}
	if (dividend < 0) {
		dividend = -(dividend);
	}
	if (divisor < 0) {
		divisor = -(divisor);
	}
	if (dividend < divisor) {
		return 0;
	}
	if (dividend == divisor) {
		return 1 * s;
	}
	if (divisor == 1) {
		return dividend;
	}
	else {
		for (int i = 1; i <= (int)abs(dividend / 2); i++) {
			if (divisor * i == dividend) {
				return s * i;
			}
			if ((dividend - divisor * i) < divisor) {
				return 0;
			}
			if (divisor * i > dividend) {
				return 0;
			}
		}
	}
	return 0;
}

int main() {
	int divisor, dividend;
	const int maxLen = 50;
	char* str1 = (char*)malloc(sizeof(char) * maxLen);
	char* str2 = (char*)malloc(sizeof(char) * maxLen);
	printf("Enter the dividend:");
	fgets(str1, maxLen, stdin);
	printf("Enter the divisor:");
	fgets(str2, maxLen, stdin);
	dividend = (int)strtol(str1, 0, 10);
	divisor = (int)strtol(str2, 0, 10);
	printf("The answer is: %d", myDiv(dividend, divisor));
	return 0;
}