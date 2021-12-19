#include <stdlib.h>
#include <stdio.h>

int main() {
	int key = 1;
	int n;
	int count = 0;
	int x;
	printf("Enter the number of multipliers\n");
	scanf("%d", &n);
	printf("Enter %d multipliers\n", n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		if (x < 0) {
			count += 1;
		}
		if (x == 0) {
			key = 0;
		}
	}
	if (key > 0) {
		if (count % 2 == 0) {
			printf("The sign is +");
		}
		else {
			printf("The sign is -");
		}
	}
	else {
		printf("The sign is 0");
	}
	return 0;
}