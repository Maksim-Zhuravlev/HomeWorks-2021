#include<stdio.h>

int main() {
	int first = 1, second = 2, last;
	int n = 9;
	if (n == 1) {
		printf("%d", first);
		return 0;
	}
	for (int i = 2; i < n; ++i) {
		last = first + second;
		first = second;
		second = last;
	}
	printf("%d", second);
}