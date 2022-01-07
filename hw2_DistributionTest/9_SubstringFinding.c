#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	int counter = 0;
	char str[600];
	char substr[600];
	printf("Enter the string:");
	scanf("%s", str);
	printf("Enter the substring being searched for:");
	scanf("%s", substr);
	
	for (int i = 0; i < (strlen(str) - strlen(substr) + 1); i++) {
		int f = 0;
		int k = 0;
		for (int j = 0; j < strlen(substr) - 1; j++) {
			if (str[i + k] != substr[j]) {
				f = 1;
				break;
			}
			k += 1;
		}
		if (f == 0) {
			counter += 1;
		}
	}
	printf("%d", counter);
	return 0;
}