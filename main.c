#include <stdio.h>

#define MAX_LEN 256

int bitAnd(int x, int y) {
    int result = ~(~x | ~y);
    return result;
}

bitXor(int x, int y) {
    int result = ~(~(x & ~y) & ~(~x & y));
    return result;
}

int thirdBits() {
    int res = 36, step = 6, first = 36;
    int step1 = step + step;
    int step2 = step1 + step1;
    res |= (res << step);
    res |= (res << step1);
    res |= (first << step2);
    return res;
}

int fitsBits(int x, int n) {
    int shift = 32 + (~n + 1);
    int newNum = x << shift;
    newNum >>= shift;
    return !(x ^ newNum);
}

int sign(int x) {
    int shift = 31;
    int is0 = !(x ^ 0);
    return !is0 | (x >> shift);
}


int getByte(int x, int n) {
    int mask = 0xFF;
    int shift = n << 3;
    mask <<= shift;
    int res = x & mask;
    return (res >> shift) & 0xFF;
}

int logicalShift(int x, int n) {
    int beg = x;
    int res;
    int isD0 = !(n ^ 0);
    int mask = (1 << (32 + (~n + 1)));
    mask += (~1 + 1);
    x >>= n;
    res = x & mask;
    return ((~isD0 + 1) & beg) | (~(~isD0 + 1) & res);
}

int addOK(int x, int y) {
    int sgnA = (x >> 31) & 1,
            sgnB = (y >> 31) & 1;
    int sum = x + y;
    int sgnAB = (sum >> 31) & 1;
    return (!sgnA | !sgnB | sgnAB) & (sgnA | sgnB | !sgnAB);

}

int bang(int x) {
    int is0 = ~((x >> 31) & 1) & ((x ^ (x + (~1 + 1))) >> 31) & 1;
    return is0;

}

int conditional(int x, int y, int z) {
    int is0 = !(x ^ 0);
    return ((~is0 + 1) & z) | (~(~is0 + 1) & y);
}

int isPower2(int x) {
    int isMore0 = (x >> 31) & 1;
    int is0 = !(x ^ 0);
    return !isMore0 & !is0 & !(x & (x + (~1 + 1)));
}




int main() {
    printf("%d\n", bitAnd(6, 5));
    printf("%d\n", bitXor(4, 5));
    printf("%d\n", thirdBits());
    printf("%d\n", fitsBits(-4, 3));
    printf("%d\n", sign(10));
    printf("%d\n", getByte(10, 2));
    printf("%d\n", logicalShift(10, 2));
    printf("%d\n", addOK(10, 2));
    printf("%d\n", bang(5));
    printf("%d\n", conditional(5, 10, 15));
    printf("%d\n", isPower2(32));
    return 0;
}
