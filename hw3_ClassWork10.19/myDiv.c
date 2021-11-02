#include<stdio.h>
#include<stdlib.h>

int myDiv(int divisor, int divident) {
	if (divident == 0) return 0;
	if (divisor == INT_MIN) {
	if (divident == -1) return 0;
	if (divident == 1) return INT_MIN;
}
	int signRes = (((divisor >> 31) << 1) + 1) * (((divident >> 31) << 1) + 1);
	divisor *= ~((divisor >> 31) << 1);
	divident *= ~((divident >> 31) << 1);
	int shift = 1;
	while (((divident << shift) >> 31) && ((divident << shift) >= divisor)) {
		++shift;
	}
	int ans = 0;
	while (shift > 0) {
		--shift;
		if ((1 << shift) * divident >= divisor) {
			ans += 1 << shift;
			divisor -= (1 << shift) * divident;
		}
	}
	return ans * signRes;
}

int main() {
	printf("%d\n", myDiv(INT_MIN, 2));
}