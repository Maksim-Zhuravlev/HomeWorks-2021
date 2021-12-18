#include <stdlib.h>
#include <stdio.h>


int bitAnd(int x, int y) {
	int z;
	z =~(~x|~y);
	return z;
}
int bitXor (int a, int b)
{   int z ;
    z= ~(~a&~b)&~(a&b);
    return z;
}
int thirdBit (int x){
    int y ;
    y = x >>1;
    return y;
}
int fitsBits (int x, int y) {
     int shift;
     shift = 33 + ~y;

    return  !(x^((x<<shift) >> shift));
}
int sign(int x) {
	int y;
	y= !(!x);
	int result;
	x = x >> 31;
	result = x | y;
	return result;
}
int getByte(int x, int y) {
	int result;
	result = (x>>(y<<3)) & 0xFF;
	return result;
}

int logicalShift(int x, int n) {
	int result;
    result = ((x >> n) - 1)& n ;
	return result;
}
int addOK (int x,int y){
    int z;
    z= !((((x+y)^x)&((x+y)^y))>>31);
    return z;
}

int bang(int x) {
	int y;
	y= ((x | (~x + 1))>>31)+1;

	return y;
}

int conditional(int x, int y, int z) {
	int result;
	int mask = !(!x);

	mask = ~mask + 1;
	result = (y & mask) | (z & ~mask);
	return result;
}
int main(void) {
	return 0;
}

