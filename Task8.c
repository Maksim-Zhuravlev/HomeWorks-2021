#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main() {
	int limit;
	scanf("%d", &limit);
	if (limit >= 2) {
		for (int number = 2; number <= limit; number++) {
			int divs_counter = 0;
			for (int divisor = 2; divisor <= sqrt(number); divisor++) {
				if (number % divisor == 0) {
					divs_counter++;
				}
			}
			if (divs_counter == 0) {
				printf("Simple number = %d\n", number);
			}
		}
	}
	else {
		printf("With this limit, there are no prime numbers :(\n");
	}


	return 0;
}