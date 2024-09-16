#include <stdio.h>
#include <stdlib.h>

int bitAnd(int x, int y){
    return ~( (~x) | (~y) );
}


int bitXor(int x, int y){
    return ~( ~(~x & y) & ~(~y & x) );
}


int thirdBits(){
    int a = 0;
    a = a | 73;
    a<<8;
    a = a | 36;
    a<<8;
    a = a | 146;
    a<< 8;
    a = a | 73;

    return a;
}


int getByte(int x, int n){
    x>>(8 * (n - 1));
    x = x&255;

    return x;
}


int fitsBits(int x, int n){
    return !( 1 + ~(x>>31) + (x >> (n + 1 + ~1)) );
}

int sign(int x){
    return ~(x>>31);
}


int bang(int x){
	return ((x | (~x + 1)) >> 31) + 1;
}


int addOK(int x, int y){
	return !((((x+y) ^ x) & ((x + y) ^ y)) >> 31);
}


int logicalShift(int x, int n){
	return (x >> n) & ~((x >> 31) << (31 + ~n + 1) << 1);
}


int conditional(int x, int y, int z) {
	return (y & (((!!x) << 31) >> 31)) | (z & (((!x) << 31) >> 31));
}


int isPower2(int x){
	return !((x >> 31) | (!x) | ((x & (~x + 1)) ^ x));
}

int main()
{
    return 0;
}
