#include <stdio.h>

int bitAnd(int x, int y) {

    return ~(~x | ~y);
}


int bitXor(int x, int y) {

    return ~(x & y) & ~(~x & ~y);
}


int thirdBits(void) {

    return (292 << 21) | (292 << 12) | (292 << 3) | 292;
}


int fitsBits(int x, int n) {
    int a = 33 + ~n;
    int b = ((x << a) >> a);

    return !(b + ~x + 1);
}


int sign(int x) {

    return (x >> 31) + (((~x) >> 31) & !(x << 1));
}


int getByte(int x, int n) {

    return (x >> (n << 3) & (0xFF));
}


int logicalShift(int x, int n) {
    int a = (x >> n);
    int b = ~(~0 << (33 + ~n));
    int c = (a & b);

    return ((((!n) << 31) >> 31) & x) + c;
}


int addOK(int x, int y) {
    int sum = x + y;

    return !(((x ^ sum) & (y ^ sum)) >> 31);
}


int bang(int x) {
    int a = (~x >> 31);
    int b = (a & 1);

    return ((b ^ (((~x + 1) >> 31) & 1)) & b);
}


int conditional(int x, int y, int z) {
    int a = ((((x >> 31) | ((~x + 1) >> 31)) << 31) >> 31);

    return ((a & y) + (~a & z));
}


int isPower2(int x) {

    return !((x >> 31) | (!x) | ((x & (~x + 1)) ^ x));
}


int main() {

    return 0;
}
