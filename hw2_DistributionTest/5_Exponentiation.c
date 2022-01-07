#include<stdio.h>

int answer(int a, int n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return a;
	}
	int r = answer(a, n / 2);
	return r * r * answer(a, n % 2);
}

int main() {
	int a, n = 1;

	printf("Enter the value a:");
	scanf("%d", &a);
	printf("Enter the value n:");
	scanf("%d", &n);

	printf("%d", answer(a, n));
	return 0;
}