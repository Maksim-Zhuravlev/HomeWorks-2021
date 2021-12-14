#include <stdio.h>
#define ull unsigned long long

void other() {
	printf("yo, wassup? 'other' is executed\n");
}

void input() {
	ull m[4];
	ull x = 1;
	ull i = 0;
	printf("&i = %llu, &x = %llu, m = %llu\n", &i, &x, m);
	printf("You can corectly enter 4 nums of ull type\n");
	printf("Address of 'other' %llu, You should enter it through position from data\n", other);
	printf("to iterrupt input enter 0\n");
	while(x) {
		printf("%p: ", &m[i]);
		scanf("%llu", &x);
		m[i++] = x;
	}
}

int main() {
	input();
	printf("no other\n");
	return 0;
}