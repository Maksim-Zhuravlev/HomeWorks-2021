#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


void other() {
	printf("Completed, function was called\n");
}
void input() {
	int data[1];
	int x = 1;
	size_t i = 0;
	while (x) {
		scanf("%d", &x);
		data[i++] = x;
	}
}

int main() {
	printf("Other: %p\n", &other);
	input();
	printf("The function was not called");
	return 0;
}