#include <stdio.h>
#include <math.h>


int powBrute(int x, int n) {
	int result = !!x;
	
	for (int i = 0; i < n; i++) {
		result *= x;
	}
	return result;
}

int powEffective(int x, int n) {
	int result = !!x;
	short binaryDigit;
	short curPosition = log(n) / log(2);
	
	while (curPosition > 0) {
		binaryDigit = (n >> curPosition) & 1;
		curPosition--;
		result = pow(result * pow(x, binaryDigit), 2);
	}
	binaryDigit = (n >> curPosition) & 1;
	result = result * pow(x, binaryDigit);
	return result;
}

int powRecursive(int x, int n) {
	if (n == 1) {
		return x;
	} else {
		return x * powRecursive(x, n - 1);
	}
}
	

void main() {
	int x, n;
	
	printf("x = ");
	scanf("%d", &x);
	printf("\nn = ");
	scanf("%d", &n);
}