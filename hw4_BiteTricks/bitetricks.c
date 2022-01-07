#include<stdio.h>

int bitAnd(int x, int y) {
	return ~(~x | ~y);
}

int bitXor(int x, int y) {
	return ~(x & y) & ~(~x & ~y);
}

int thirdBits(void) {
	int result = 4;
	result = (result << 3) + result;
	result = (result << 6) + result;
	result = (result << 12) + result;
	result = (result << 24) + result;
	return result;
}

int fitsBits(int x, int n) {
	return !(x ^ ((x << (33 + ~n)) >> (33 + ~n)));
}

int sign(int x) {
	return x >> 31 | !(!x);
}

int getByte(int x, int n) {
	return (x >> (n << 3)) & 0xff;
}

int logicalShift(int x, int n) {
	return (x >> n) & (~(((1 << 31) >> n) << 1));
}

int addOK(int x, int y) {
	return !((((x + y) ^ x) & ((x + y) ^ y)) >> 31);
}

int bang(int x) {
	return (((~x + 1) | x) >> 31) + 1;
}

int conditional(int x, int y, int z)  {
	return z ^ ((y ^ z) & ((!x) + ~0));
}

int isPower2(int x) {
	return !(x & (x + ~(x >> 31))) & !(!x);
}

int main() {
	return 0;
}