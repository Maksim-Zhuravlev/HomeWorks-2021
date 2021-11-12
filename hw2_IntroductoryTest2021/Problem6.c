#include<stdio.h>

int main() {
	int a[10] = { 2,3,-4,-2,-4,-2,0,7,-1,-1 };
	int sign = 1;
	for (int i = 0; i < 10; ++i) {
		if (a[i] == 0) {
			printf("0");
			return 0;
		}
		if (a[i] < 0) {
			sign *= -1;
		}
	}
	if (sign < 0) {
		printf("-");
	}
	else {
		printf("+");
	}
	return 0;
}