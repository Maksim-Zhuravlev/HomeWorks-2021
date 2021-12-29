#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int bitAnd(int x, int y){
	return ~(~x | ~y);
}

int bitXor(int x, int y){
	return ~(x & y) & ~(~x & ~y);
}

int thirdBits(void){
	return (36 << 24) | (146 << 16) | (73 << 8) | 36;
}

int fitsBits(int x, int n) {
	x = x >> (n + (~1 + 1));
	return !x | !(x ^ (~1 + 1));
}

int sign(int x) {
	return (!!x) | (x >> 31);
}

int getByte(int x, int n) {
	return (x >> (n << 3)) & 255;
}

int logicalShift(int x, int n) {
	int mask = ((1 << 31) >> n) << 1;
	return (x >> n) & ~mask;
}

int addOK(int x, int y) {
	int sum = x + y;
	return !((x ^ sum) & (y ^ sum) >> 31);
}

int bang(int x) {
	return ((x | (~x + 1)) >> 31) + 1;
}

int conditional(int x, int y, int z) {
	int mask = ~(!(!x) + (~1 + 1));
	return (y & mask) | (z & ~mask);
}

int isPower2(int x) {
	return !(x >> 31 & 1) & !!x & !(x & (x + ~0));

}

int main() {
	return 0;
}