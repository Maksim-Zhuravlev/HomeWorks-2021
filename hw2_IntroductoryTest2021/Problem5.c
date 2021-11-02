#include<stdio.h>

int degree(int a, int n) {
	if (n == 0) return 1;
	if (n == 1) return a;
	int res = degree(a, n / 2);
	return res * res * degree(a, n % 2);
}

int main() {
	int a = 5, n = 4;
	printf("%d", degree(a, n));
	return 0;
}