#include <stdio.h>


void other() {
	printf("Other function is running\n");
}

void input() {
	int arr[2];
	int i = 1;
	int x;
	
	printf("Enter the Jump integer(above) in the 5th step or enter 0 to exit\n\n");
	while (1) {
		printf("%d) Enter your number: ", i);
		scanf("%d", &x);
		printf("\n");
		if (x == 0) {
			break;
		}
		*(arr + i) = x;
		i++;
	}
}


void main() {	
	printf("\nJump integer = %d\n\n", other);
	input();
	printf("This text will not be printed\n");
}	
	
