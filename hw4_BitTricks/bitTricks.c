#include<stdio.h>

int bitAnd(int x, int y) {
	return ~(~x | ~y);
}

int bitXor(int x, int y) {
	return ~(~(~x & y) & ~(x & ~y));
}

int thirdBits(void) {
	int res = 4;
	res = (res << 3) + res;
	res = (res << 6) + res;
	res = (res << 12) + res;
	res = (res << 24) + res;
	return res;
}

int fitsBits(int x, int n) {
	return !(1+~(x >> 31) + (x >> (n + 1 + ~1)));
}

int sign(int x) {
	return (x >> 31) + (x >> 31) + (!!x);
}

int getByte(int x, int n) {
	return (x >> (n << 3)) & 255;
}

int logicalShift(int x, int n) {
	return (x >> n) & ~((x >> 31) << (31 + ~n + 1) << 1);
}

int addOK(int x, int y) {
	return !((((x+y) ^ x) & ((x + y) ^ y)) >> 31);
}

int bang(int x) {
	return ((x | (~x + 1)) >> 31) + 1;
}

int conditional(int x, int y, int z) {
	return (y & (((!!x) << 31) >> 31)) | (z & (((!x) << 31) >> 31));
}

int isPower2(int x) {
	return !((x >> 31) | (!x) | ((x & (~x + 1)) ^ x));
}

int main() {
	printf("%d", conditional(0,4,5));
}