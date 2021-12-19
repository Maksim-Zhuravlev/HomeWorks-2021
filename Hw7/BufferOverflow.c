#include <stdio.h>

void other() {
	printf("But this text was printed.\n");
}

void input() {
	int array[3];
	int i = 1;
	int x;

	printf("Enter the numbers in order.\n");
	printf("Enter Other function adress in the 7th step.\n");
	printf("To stop enter 0.\n\n");
	while (x) {
		printf("%d) Enter number: ", i);
		scanf("%d", &x);
		array[i] = x;
		i++;
	}
}


void main() {
	printf("Other function adress = %d\n", other);
	input();
	printf("Usually this text should be printed\n");
}