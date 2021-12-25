#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


int bitAnd(int x, int y) {
	int z;
	z =~(~x|~y);
	return z;
}
int bitXor (int x, int y)
{   int z ;
    z= ~(~x&~y)&~(x&y);
    return z;
}
int thirdBits(void)
{
    int x = 36;
    x = (x << 6) | x;
    x = (x << 6) | x;
    x = (x << 6) | x;
    x = (x << 6) | x;
    return (x);
}

int fitsBits(int x, int y)
{
    int z = ~1 + 1;
    x = x >> (y + z);
    return !x | !(x ^ z);
}

int sign(int x)
{
    int shift = 31;
    int null = !(x ^ 0);
    return !null | (x >> shift);
}
int getByte(int x, int y)
{
    int mask = 0xFF;
    int shift = y << 3;
    mask <<= shift;
    int num = x & mask;
    return (num >> shift) & 0xFF;
}
int logicalShift(int x, int y) {
	return (~((x >> 31) << (31 + ~y + 1) << 1) & x >> y);
}

int addOK (int x,int y){

    return !((((x+y)^x)&((x+y)^y))>>31);
}

int bang(int x) {

	return ((x | (~x + 1))>>31)+1;
}

int conditional(int x, int y, int z)
{
    return (((~(!(!x)) + 1) & y) | ((~(!x) + 1) & z));
}
int isPower2(int x) {
	return !(x & (x + ~(x >> 31))) & !(!x);
}

int main() {
	return 0;
}
