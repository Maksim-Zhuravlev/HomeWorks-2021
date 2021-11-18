#include <stdio.h>
#include <stdlib.h>


int bitAnd(int x, int y) {
	return ~(~x | ~y);
}

int bitXor(int x, int y) {
	return ~(x & y) & ~(~x & ~y);
}

int thirdBits(void) {
	int ans = 4;
	ans = (ans << 3) + ans;
	ans = (ans << 6) + ans;
	ans = (ans << 12) + ans;
	ans = (ans << 24) + ans;
	return ans;
}

int fitsBits(int x, int n) {
	int shift = (32 + ~n + 1);
	return !(x ^ ((x << shift) >> shift));
}

int sign(int x) {
	return (!!x | (x >> 31));
}

int getByte(int x, int n) {
	int shift = n << 3;
	return ((x >>shift) & 255);
}

int logicalShift(int x, int n) {
	return (~((x >> 31) << (31 + ~n + 1) << 1) & x >> n);
}

int addOK(int x, int y) {
	return !((((x + y) ^ x) & ((x + y) ^ y)) >> 31);
}

int bang(int x) {
	return (((~x + 1) | x) >> 31) + 1;
}

int conditional(int x, int y, int z) {
	int key = ~(~(!x - 1));
	return (y & key) | (z & ~key);
}

int isPower2(int x) {
	return !(x & (x + ~(x >> 31))) & !(!x);
}

int main() {
	return 0;
}