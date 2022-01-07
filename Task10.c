#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main() {

	int index;
	unsigned long long previous = 1, current = 1, next;
	printf("Please, input the index of the Fibonacci number, which is >= 0, you want to find:\n");
	scanf("%d", &index);
	if (index < 0) {
		printf("There are no Fibonacci numbers with negative index!\n");
		return 0;
	}
	for (int i = 0; i < index; i++) {
			next = previous + current;
			previous = current;
			current = next; 
	}
	
	printf("\nFibonacci number with index %d = %lld\n", index, current);

	return 0;
}